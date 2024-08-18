#include <iostream>
#include <string>
#include <vector>
#include "Defines.h"

using namespace std;

const int SHORT_BYTES = 2;
const int INT_BYTES = 4;
const int LONG_BYTES = 8;

struct Parser {
    const string & commands;
    const char * rawDataBytes;
    const size_t rawDataBytesCount;
    vector<long long> & outParsedNumbers;

    size_t curPos;

    Parser(const string & commands,
           const char * rawDataBytes,
           const size_t	rawDataBytesCount,
           std::vector<long long> & outParsedNumbers) :
            commands(commands),
            rawDataBytes(rawDataBytes),
            rawDataBytesCount(rawDataBytesCount),
            outParsedNumbers(outParsedNumbers),
            curPos(0)
    {};

    bool hasSpace (size_t bytes) {
        return (rawDataBytesCount - curPos) >= bytes;
    }

    ErrorCode parseShort() {
        if (!hasSpace(SHORT_BYTES)) {
            return ErrorCode::PARSE_FAILURE;
        }

        short s = *(short *)(rawDataBytes + curPos);
        curPos += SHORT_BYTES;
        outParsedNumbers.push_back(s);

        return ErrorCode::PARSE_SUCCESS;
    }

    ErrorCode parseInt() {
        if (!hasSpace(INT_BYTES)) {
            return ErrorCode::PARSE_FAILURE;
        }

        int s = *(int *)(rawDataBytes + curPos);
        curPos += INT_BYTES;
        outParsedNumbers.push_back(s);

        return ErrorCode::PARSE_SUCCESS;
    }

    ErrorCode parseLong() {
        if (!hasSpace(LONG_BYTES)) {
            return ErrorCode::PARSE_FAILURE;
        }

        long long s = *(long long *)(rawDataBytes + curPos);
        curPos += LONG_BYTES;
        outParsedNumbers.push_back(s);

        return ErrorCode::PARSE_SUCCESS;
    }

    ErrorCode parse(void) {
        for (char c : commands) {
            ErrorCode res;

            switch (c) {
                case 's':
                  res = parseShort();
                  break;
                case 'i':
                    res = parseInt();
                    break;
                case 'l':
                    res = parseLong();
                    break;
            }
            if (res != ErrorCode::PARSE_SUCCESS) {
                return res;
            }
        }
        return ErrorCode::PARSE_SUCCESS;
    }

};

ErrorCode parseData(const std::string & commands,
                    const char * rawDataBytes,
                    const size_t rawDataBytesCount,
                    std::vector<long long> & outParsedNumbers) {

    if (rawDataBytesCount == 0 || commands.empty()) {
        return ErrorCode::PARSE_EMPTY;
    }

    Parser p(commands, rawDataBytes, rawDataBytesCount, outParsedNumbers);

    return p.parse();
}

void printResult(const ErrorCode errorCode, const vector<long long> & parsedNumbers) {
    for (long long curr : parsedNumbers) {
        cout << curr << " ";
    }

    switch (errorCode) {
        case ErrorCode::PARSE_SUCCESS:
            break;
        case ErrorCode::PARSE_EMPTY:
            cout << "No input provided";
            break;
        case ErrorCode::PARSE_FAILURE:
            cout << "Warning, buffer underflow detected";
            break;
    }
    cout << endl;
}
