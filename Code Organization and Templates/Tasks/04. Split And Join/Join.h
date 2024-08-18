#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <sstream>
#include <vector>
#include <ostream>

template<class T>
std::string join(const std::vector<T> & v, const std::string & joinStr) {
    std::ostringstream ostr;

    bool bFirst = true;
    for (const T & curr : v) {
        if (!bFirst) {
            ostr << joinStr;
        }
        else {
            bFirst = false;
        }
        ostr << curr;
    }

    return ostr.str();
}

#endif
