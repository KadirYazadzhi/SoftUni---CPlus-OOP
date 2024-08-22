#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <memory>
#include <stack>

#include "CalculationEngine.h"
#include "InputInterpreter.h"
#include "Operation.h"
#include "MultiplicationOperation.h"

class AdvancedInterpreter : public InputInterpreter {

    class DivisionOperation : public Operation {
        private:
            std::vector<int> operands;
            int result;
        public:
            void addOperand(int operand) override {
                this->operands.push_back(operand);

                if (this->isCompleted()) {
                    this->result = this->operands[0] / this->operands[1];
                }
            }

            bool isCompleted() override {
                return this->operands.size() == 2;
            }

            int getResult() override {
                return this->result;
            }
    };

    class MemorySaveOperation : public Operation {
        private:
            std::stack<int> memory;
        public:
            void addOperand(int operand) override {
                this->memory.push(operand);
            }

            bool isCompleted() override {
                return false;
            }

            int getResult() override {
                if (memory.size() == 0) {
                    return 0;
                }
                int top = memory.top();
                memory.pop();
                return top;
            }
    };

    class MemoryReadOperation : public Operation {
    private:
        MemorySaveOperation & ms;

    public:
        MemoryReadOperation(MemorySaveOperation & ms) : ms(ms) {};

        virtual void addOperand(int operand) override {}

        virtual int getResult() override {
            return ms.getResult();
        }

        virtual bool isCompleted() override {
            return true;
        }
    };

    public:
        AdvancedInterpreter(CalculationEngine & engine)
                : InputInterpreter(engine),
                ms(std::make_shared<MemorySaveOperation>()) {}

        virtual std::shared_ptr<Operation> getOperation(std::string operation) override {
            if (operation == "/") {
                return std::make_shared<DivisionOperation>();
            }
            else if (operation == "ms") {
                return ms;
            }
            else if (operation == "mr") {
                return std::make_shared<MemoryReadOperation>(*ms.get());
            }

            return InputInterpreter::getOperation(operation);
        }

    protected:
        std::shared_ptr<MemorySaveOperation> ms;

};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine & engine) {
    std::shared_ptr<InputInterpreter> ret = std::make_shared<AdvancedInterpreter>(engine);

    return ret;
}

#endif
