#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> operator + (const vector<string> & a, const vector<string> & b) {
    vector<string> res;

    res.reserve(a.size());

    for (size_t i = 0; i < a.size(); i++) {
        res.push_back(a[i] + " " + b[i]);
    }

    return res;
}

#endif


