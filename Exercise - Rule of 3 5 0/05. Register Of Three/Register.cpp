#include <iostream>
#include <algorithm>
#include "Register.h"

using namespace std;

Register::~Register() {
    delete[] companiesArray;
}

Register & Register::operator=(const Register &other) {
    if (this == &other) {
        return *this;
    }

    Company *otherCompanies = new Company[other.numAdded];
    std::copy(other.companiesArray, other.companiesArray + other.numAdded, otherCompanies);

    delete[] companiesArray;
    companiesArray = otherCompanies;
    numAdded = other.numAdded;

    return *this;
}

Register::Register(const Register& other) : numAdded(0), companiesArray(nullptr) {
    *this = other;
}

Register::Register(size_t numCompanies) : Register() {
    companiesArray = new Company[numCompanies];
}

void Register::add(const Company &c) {
    companiesArray[numAdded++] = c;
}

Company Register::get(int companyId) const {
    for (size_t curr = 0; curr < numAdded; curr++) {
        if (companiesArray[curr].getId() == companyId) {
            return companiesArray[curr];
        }
    }
    return Company();
}
