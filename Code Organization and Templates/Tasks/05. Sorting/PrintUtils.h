#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>

template<class T>
void printContainer(typename T::iterator begin, typename T::iterator end) {
    for (; begin != end; begin++) {
        std::cout << *begin << ' ';
    }
}

#endif
