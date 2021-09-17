#include "Fraction.h"

int gcd (int a, int b) {
    if (a == b) return a;

    if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(b - a, a);
    }
}

// ---------------------------------------

Fraction::Fraction(int numerator, int denominator) : denominator(denominator), numerator(numerator) {
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    Fraction::numerator = numerator;
    reduce();
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    Fraction::denominator = denominator;
    reduce();
}

Fraction Fraction::mul(const Fraction &ref) const {
    return {numerator * ref.numerator, denominator * ref.denominator};
}

Fraction Fraction::div(const Fraction &ref) const {
    return {numerator * ref.denominator, denominator * ref.numerator};
}

bool Fraction::equal(const Fraction &ref) const {
    return denominator == ref.denominator && numerator == ref.numerator;
}

Fraction Fraction::operator*(const Fraction &ref) const {
    return mul(ref);
}

Fraction Fraction::operator/(const Fraction &ref) const {
    return div(ref);
}

bool Fraction::operator==(const Fraction &ref) const {
    return equal(ref);
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
    return os;
}

void Fraction::reduce() {
    int gcdV = gcd(abs(numerator), denominator);
    if (gcdV == 1) return;

    numerator /= gcdV;
    denominator /= gcdV;
}