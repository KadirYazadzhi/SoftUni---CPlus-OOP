#ifndef ARRAYOFPOINTERS_H
#define ARRAYOFPOINTERS_H

#include <vector>
#include <memory>

class ArrayOfPointers {
private:
    std::vector<std::unique_ptr<Company>> data;

public:
    void add(Company * c) {
        data.push_back(std::unique_ptr<Company>(c));
    }

    size_t getSize(void) const {
        return data.size();
    }

    Company * get(size_t idx) {
        return data[idx].get();
    }
};

#endif
