#include "Range.h"
#include <algorithm>

Range::Range() : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {}

bool Range::empty() const {
    return valueCounts == nullptr;
}

void Range::clear() {
    if (!empty()) {
        delete [] valueCounts;
        valueCounts = nullptr;
        rangeFirst = rangeLength = 0;
    }
}

Range::Range(const Range &other) : Range() {
    *this = other;
}

Range & Range::operator=(const Range &other) {
    clear();
    this->rangeFirst = other.rangeFirst;
    this->rangeLength = other.rangeLength;
    this->valueCounts = copyValues(other);

    return *this;
}

Range::~Range() {
    clear();
};

size_t Range::getIndex(T value) const {
    return value - rangeFirst;
}

size_t Range::getCount(T value) const {
    if (value >= rangeFirst && value < (rangeFirst + rangeLength)) {
        return valueCounts[getIndex(value)];
    }
    else {
        return 0;
    }
}

void Range::add(T value) {
    T first = rangeFirst;
    T last = rangeFirst + rangeLength - 1;

    if (empty()) {
        resize(value, value);
    }
    else if (value < first) {
        resize(value, last);
    }
    else if (value > last) {
        resize(first, value);
    }
    valueCounts[getIndex(value)]++;
}

void Range::resize(T first, T second) {
    T newFirst = first;
    T newLen = second - first + 1;

    size_t * newCounts = new size_t[newLen] {0};

    if (!empty()) {
        std::copy(
                valueCounts,
                valueCounts + rangeLength,
                newCounts + (rangeFirst - first)
        );

        clear();
    }

    rangeFirst = first;
    rangeLength = newLen;
    valueCounts = newCounts;
}