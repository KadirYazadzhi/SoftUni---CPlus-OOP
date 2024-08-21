#include "IndexedSet.h"

#include <set>

using namespace std;

IndexedSet::IndexedSet() : valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet & other) : IndexedSet() {
    *this = other;
}

void IndexedSet::clearIndex() {
    if (valuesArray) {
        delete [] valuesArray;
        valuesArray = nullptr;
    }
}

IndexedSet::~IndexedSet() {
    clearIndex();
}

void IndexedSet::add(const Value & v) {
    if (valuesSet.insert(v).second) {
        clearIndex();
    }
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

IndexedSet & IndexedSet::operator=(const IndexedSet &other) {
    if (this != &other) {
        clearIndex();
        this->valuesSet = other.valuesSet;
    }
    return *this;
}

const Value & IndexedSet::operator[](size_t index) {
    if (valuesArray == nullptr) {
        buildIndex();
    }

    return valuesArray[index];
}

void IndexedSet::buildIndex() {
    clearIndex();

    valuesArray = new Value[valuesSet.size()];
    size_t idx = 0;

    for (const Value & v : valuesSet) {
        valuesArray[idx++] = v;
    }
}