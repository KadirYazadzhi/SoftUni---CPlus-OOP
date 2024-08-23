#ifndef SORTBY_H
#define SORTBY_H

#include "Company.h"
#include <algorithm>

void sortBy(Company** start, Company** end, bool(*compare)(const Company& a, const Company& b)) {
    struct SortFunc {
        bool(*compare)(const Company& a, const Company& b);

        SortFunc(bool(*compare)(const Company& a, const Company& b)) : compare(compare) {}

        bool operator() (const Company* first, const Company* second) const {
            return compare(*first, *second);
        }
    };

    std::sort(start, end, SortFunc(compare));
}

#endif

