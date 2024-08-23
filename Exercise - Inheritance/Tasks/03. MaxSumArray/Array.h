#ifndef ARRAY_H
#define ARRAY_H

#include <vector>

template<typename T> class Array : public std::vector<T> {
public:
    Array (size_t size = 0) : std::vector<T>(size) {}

    size_t getSize(void) const {
        return this->size();
    }
};

#endif
