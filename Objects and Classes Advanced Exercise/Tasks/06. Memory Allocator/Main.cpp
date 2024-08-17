#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Defines.h"

using namespace std;

class Command {
    static int allocated;
    string command;
    int idx;

    vector<int *> &memory;

private:
    ErrorCode allocate() {
        if (memory[idx] == nullptr) {
            memory[idx] = &allocated;
            return ErrorCode::EXECUTE_SUCCESS;
        } else
            return ErrorCode::MEMORY_LEAK;
    }

    ErrorCode deallocate() {
        if (memory[idx] == &allocated) {
            memory[idx] = nullptr;
            return ErrorCode::EXECUTE_SUCCESS;
        } else
            return ErrorCode::DOUBLE_FREE;
    }

public:
    Command(const string &cmd, vector<int *> &memory) : memory(memory) {
        istringstream istr(cmd);
        istr >> command;
        if (command != "Idle")
            istr >> idx;
        else
            idx = 0;
    }

    ErrorCode execute() {
        if (idx >= memory.size())
            return ErrorCode::INDEX_OUT_OF_BOUND;
        if (command == "Allocate")
            return allocate();
        if (command == "Deallocate")
            return deallocate();
        if (command == "Idle")
            return ErrorCode::EXECUTE_IDLE;

        return ErrorCode::EXECUTE_SUCCESS;
    }
};

int Command::allocated = 1;

ErrorCode executeCommand(const string &command, vector<int *> &memory) {
    Command c(command, memory);

    return c.execute();
}

void printResult(const ErrorCode errorCode, const string &command) {
    switch (errorCode) {
        case ErrorCode::EXECUTE_SUCCESS:
            cout << command << " - " << "success" << endl;
            break;
        case ErrorCode::DOUBLE_FREE:
            cout << command << " - " << "system crash prevented, will skip this deallocation" << endl;
            break;
        case ErrorCode::EXECUTE_IDLE:
            cout << command << " - " << "this exam is a piece of cake! Where is the OOP already?!?" << endl;
            break;
        case ErrorCode::INDEX_OUT_OF_BOUND:
            cout << command << " - " << "out of bound" << endl;
            break;
        case ErrorCode::MEMORY_LEAK:
            cout << command << " - " << "memory leak prevented, will not make allocation" << endl;
            break;
    }
}