#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include "Vector.h"

class VectorLengthComparer {
    public:
        bool operator() (const Vector & a, const Vector & b) const {
            return a.getLength() < b.getLength();
        }
};

template<typename T, typename Comparer>
class ReverseComparer {
    private:
        Comparer comp;

    public:
        bool operator() (const T & a, const T & b) const {
            return !comp(a, b);
        }
};

#endif
