#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <sstream>
#include <vector>
#include <ostream>

template<class T>
std::string join(const std::vector<T> & v, const std::string & joinStr) {
    std::ostringstream ostr;

    for (const T & curr : v) {
        ostr << curr << joinStr;
    }

    return ostr.str();
}

#endif
