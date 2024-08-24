#ifndef CITYUTILS_H
#define CITYUTILS_H

#include "City.h"
#include <string>
#include <map>

const City * initCity(const std::string & name, size_t population) {
    return new City(name, population);
}

std::map<size_t, const City *> groupByPopulation(std::vector<const City*> & cities, size_t & totalPopulation) {
    totalPopulation = 0;

    std::map<size_t, const City *> ret;
    for (auto c : cities) {
        ret[c->getPopulation()] = c;
        totalPopulation += c->getPopulation();
    }

    return ret;
}

#endif
