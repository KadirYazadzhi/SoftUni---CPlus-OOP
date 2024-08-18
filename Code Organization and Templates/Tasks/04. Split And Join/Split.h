#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>
#include <sstream>
#include <istream>

template<class T>
std::vector<T> split(const std::string & line, char separator) {
    std::istringstream is(line);
    std::vector<T> res;

    while (true) {
        std::string buffer;
        if (!getline(is, buffer, separator)) {
            break;
        }

        std::istringstream eltS(buffer);
        T t;
        eltS >> t;
        res.push_back(t);
    }

    return res;
}

#endif
