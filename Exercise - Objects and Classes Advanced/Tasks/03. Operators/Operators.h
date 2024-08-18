#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> & operator << (std::vector<std::string> & vectorString, const std::string & lineToAdd) {
    vectorString.push_back(lineToAdd);
    return vectorString;
}

std::string operator + (const std::string & str, int i) {
    std::ostringstream ostr;
    ostr << str << i;

    return ostr.str();
}

std::ostream & operator << (std::ostream & ostr, const std::vector<std::string> & vect) {
    for (const std::string & curr : vect) {
        ostr << curr << std::endl;
    }
    return ostr;
}


#endif

