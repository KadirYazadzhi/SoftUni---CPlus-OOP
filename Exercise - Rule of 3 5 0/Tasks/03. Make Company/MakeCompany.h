#ifndef MAKECOMPANY_H
#define MAKECOMPANY_H

#include "Company.h"
#include <memory>
#include <vector>
#include <string>

std::shared_ptr<Company> makeCompany (const std::vector<std::string & props) {
    int id = stoi(props[0]);

    std::string name = props[1];

    std::vector<std::pair<char, char>> employees;

    for (size_t currPair = 2; currPair < props.size(); currPair++) {
        employees.push_back(std::pair<char, char>(props[currPair][0], props[currPair][1]));
    }

    std::shared_ptr<Company> result = std::make_shared<Company>(id, name, employees);
}

#endif
