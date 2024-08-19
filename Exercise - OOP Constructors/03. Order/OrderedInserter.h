#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H

#include "Company.h"
#include <vector>
#include <algorithm>

class OrderedInserter {
    private:
        typedef std::vector<const Company*> companyVector;
        companyVector &companies;

    public:
        OrderedInserter(companyVector & companies) : companies(companies) {}

        void insert(const Company *c) {
            companyVector::iterator it = std::find_if(companies.begin(),
                                                      companies.end(),
                                                      [c] (const Company *curr) {
                                                          return curr->getId() > c->getId();
                                                      });

            companies.insert(it, c);
        }
};

#endif

