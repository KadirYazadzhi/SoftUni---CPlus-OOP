#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "CommandInterface.h"

class AdvancedCommandInterface : public CommandInterface {
    class CutTransform : public TextTransform {
        std::string contents;

    public:
        virtual void invokeOn(std::string & text, int startIndex, int endIndex) override {
            contents = text.substr(startIndex, endIndex - startIndex);

            text.erase(startIndex, endIndex - startIndex);
        }

        const std::string & getContents(void) const {
            return contents;
        }
    };

    class PasteTransform : public TextTransform {
    public:
        PasteTransform(std::shared_ptr<CutTransform> cutTransform) : cutTransform(cutTransform) {}

        virtual void invokeOn(std::string & text, int startIndex, int endIndex) override {
            text.erase(startIndex, endIndex - startIndex);
            text.insert(startIndex, cutTransform->getContents());
        }

    protected:
        std::shared_ptr<CutTransform> cutTransform;
    };

public:
    AdvancedCommandInterface(std::string & text) : CommandInterface(text), cutTransform(std::shared_ptr<CutTransform>(new CutTransform())) {}

    virtual std::vector<Command> initCommands() override {
        std::vector<Command> res = CommandInterface::initCommands();

        res.push_back(Command("cut", cutTransform));
        res.push_back(Command("paste", std::make_shared<PasteTransform>(cutTransform)));

        return res;
    }

protected:
    std::shared_ptr<CutTransform> cutTransform;
};

std::shared_ptr<CommandInterface> buildCommandInterface(std::string & text) {
    std::shared_ptr<CommandInterface> ret = std::make_shared<AdvancedCommandInterface> (text);

    ret->init();

    return ret;
}

#endif
