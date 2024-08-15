#include <numeric>

class Fraction {
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

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

    Fraction operator + (const Fraction & other) const {

        return Fraction (
            this->numerator * other.denominator + other.numerator * this->denominator,
            this->denominator * other.denominator
        );
    }

    Fraction operator - (const Fraction & other) const {

        return Fraction (
                this->numerator * other.denominator - other.numerator * this->denominator,
                this->denominator * other.denominator
        );
    }

    friend std::istream & operator >> (std::istream & is, Fraction &f);

    bool operator == (const Fraction & other) const {

        return this->numerator == other.numerator && this->denominator == other.denominator
    }

    protected void reduce() {
        int gcd = std::gcd(numerator, denominator);

        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
    }
};

inline std::istream & operator >> (std::istream & is, Fraction &f) {
    is >> f.numerator >> f.denominator;
    f.reduce();
    return is;
}

std::ostream & operator << (std::ostream & os, const Fraction & f) {
    return os << f.getNumerator() << "/" << f.getDenominator();
}