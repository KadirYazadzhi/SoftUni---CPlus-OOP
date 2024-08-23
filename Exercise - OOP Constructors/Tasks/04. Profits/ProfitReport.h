#ifndef PROFITREPORT_H
#define PROFITREPORT_H

#include "Company.h"
#include "ProfitCalculator.h"
#include <sstream>

typedef std::map<int, ProfitCalculator> CalcMap;
std::string getProfitReport (Company * from, Company * to, CalcMap & calcs) {
    std::ostringstream ostr;
    for (; from != to + 1; from++) {
        int profit = calcs[from->getId()].calculateProfit(*from);
        ostr << from->getName() << " = " << profit << std::endl;
    }

    return ostr.str();
}

#endif
