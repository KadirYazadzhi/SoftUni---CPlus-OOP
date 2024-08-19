#include <iostream>
#include <string>
#include <sstream>
#include "TryParse.h"

using namespace std;

bool tryParse(const string & str, int & i) {
    istringstream istr(str);
    istr >> i;
    
    return(bool) istr;
}

