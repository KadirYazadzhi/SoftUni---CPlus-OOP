#ifndef INCLUDES_H
#define INCLUDES_H

#include "City.h"
#include <vector>
#include <iostream>
#include <sstream>

std::istream & operator >> (std::istream & is, City & c) {
    unsigned int censusYear;
    std::string name;
    size_t population;

    is >> name >> population >> censusYear;
    c = City(censusYear, name, population);

    return is;
}

class CityDiff {
    private:
        City a, b;

    public:
        CityDiff(const City & a, const City & b) : a(a), b(b) {}

        friend std::ostream & operator << (std::ostream & ostr, const CityDiff & cd);
};

CityDiff operator - (const City & a, const City & b) {
    return CityDiff(a, b);
}

std::ostream & operator << (std::ostream & ostr, const CityDiff & cd) {
    if (cd.a.getName() == cd.b.getName()) {
        ostr << cd.a.getName() << " (" << cd.a.getCensusYear() << " vs. " << cd.b.getCensusYear() << ")" << std::endl;
    }
    else {
        ostr << cd.a.getName() << " (" << cd.a.getCensusYear() << ") vs. " << cd.b.getName() << " (" << cd.b.getCensusYear() << ")" << std::endl;
    }

    int popDiff = cd.a.getPopulation() - cd.b.getPopulation();

    ostr << "population: ";
    if (popDiff >= 0) {
        ostr << "+";
    }
    ostr << popDiff << std::endl;
}

#endif
