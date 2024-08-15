#include <iostream>
#include <set>

class Fraction {
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

	int getNumerator() {
		return this->numerator;
	}

	int getDenominator() {
		return this->denominator;
	}

	bool operator<(const Fraction& other) const {
		return this->numerator * other.denominator < other.numerator * this->denominator;
	}

    Fraction operator ++ (int) {
        Fraction curr = *this;

        numerator = denominator;

        return currl
    }

    Fraction & operator ++ (void) {
        numerator += denominator;

        return *this;
    }

    friend istream & operator >> (istream & is, Fraction &f);
};

inline istream & operator >> (istream & is, Fraction &f) {
    return is >> f.numerator >> f.denominator;
}