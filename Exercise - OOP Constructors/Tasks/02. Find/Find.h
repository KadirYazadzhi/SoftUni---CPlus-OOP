#ifndef FIND_H
#define FIND_H

#include "Company.h"
#include <vector>

typedef std::vector<Company*> VectorCompany;
Company * find(VectorCompany & companies, int searchId) {
    for (auto c : companies) {
        if (c->getId() == searchId) {
            return c;
        }
    }

    return nullptr;
}

#endif
