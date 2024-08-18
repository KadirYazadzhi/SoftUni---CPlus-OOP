#ifndef PRINTUTILS_H
#define PRINTUTILS_H

template <typename T>
printVector(T & v) {
    typename T::iterator itC = v.begin();

    for (; itC != v.end; itC++) {
        std::cout << *itC << ' ';
    }
    std::cout << std::endl;
}

#endif
