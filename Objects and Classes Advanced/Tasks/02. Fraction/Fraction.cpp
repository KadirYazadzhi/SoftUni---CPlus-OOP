#include <iostream>
#include <set>

#include "Fraction.h"

using namespace std;

int main() {
    set<Fraction> fractions {
        Fraction {1, 3},
        Fraction {2, 10},
        Fraction {2, 6}
    };

    Fraction f13 {1, 3},
             f24 {2, 4},
             f25 {2, 5};

    Fraction f43 = f13++;
    Fraction f43b = ++f13;

    Fraction myF1;

    cin >> myF1;
    cout << "You entered: " << myF1 << " value." << endl;

    Fraction fR = myF1 + f13;
    cout << fR << endl;

    fR = myF1 - Fraction(1, 12);
    cout << fR << endl;

    Fraction first, second;
    cin >> first >> second;

    cout << (first == second) << endl;

    return 0;
}