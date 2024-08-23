#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H

#include "Company.h"
#include <list>

void removeInvalid(std::list<Company*> & companies) {
    std::list<Company*>::iterator it = companies.begin();

    for (;it != companies.end(); ) {
        if ((*it)->getId() < 0) {
            delete * it;
            it = companies.erase(it);
        }
        else {
            it++;
        }
    }
}

#endif
