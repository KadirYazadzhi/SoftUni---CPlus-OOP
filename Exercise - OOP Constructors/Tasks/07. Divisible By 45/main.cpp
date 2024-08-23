#include "BigInt.h"
#include <iostream>

using namespace std;

bool divisibleBy5(const BigInt & num) {
    string digits = num.getDigits();
    char lastDigit = digits[digits.length() - 1];

    return lastDigit == '0' || lastDigit == '5';
}

bool divisibleBy9(const BigInt & num) {
    string digits = num.getDigits();
    size_t sumOfDigits = 0;

    for (char c : digits) {
        sumOfDigits += (c - '0');
    }

    return (sumOfDigits % 9 == 0);
}

bool divisibleBy45(const BigInt & num) {

    return divisibleBy5(num) & divisibleBy9(num);
}

int main() {
    string fromS, toS;

    cin >> fromS >> toS;

    BigInt from(fromS), to(toS);

    for (; from < to; ) {
        if (divisibleBy45(from)) {
            cout << from << endl;
        }

        from += 1;
    }

    return 0;
}
