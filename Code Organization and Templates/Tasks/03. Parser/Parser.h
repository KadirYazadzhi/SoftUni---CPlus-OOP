#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <string>
#include <sstream>

template <typename T>
class Parser {
    private:
        std::istream & is;
        std::string stopLine;
    public:
        Parser(std::istream & is, std::string stopLine) : is(is), stopLine(stopLine) {}

        bool readNext(T & t) {
            std::string line;
            getline(is, line);
            if (line == stopLine) {
                return false;
            }
            std::istringstream istr(line);
            istr >> t;

            return true;
        }
};

#endif
