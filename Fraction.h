#pragma once
#include <cmath>
#include <ostream>

class Fraction {
    public:
        Fraction(int numerator, int denominator);

        [[nodiscard]] int getNumerator() const;
        void setNumerator(int numerator);
        [[nodiscard]] int getDenominator() const;
        void setDenominator(int denominator);

        [[nodiscard]] Fraction mul(const Fraction &ref) const;
        [[nodiscard]] Fraction div(const Fraction &ref) const;
        [[nodiscard]] bool equal(const Fraction &ref) const;

        Fraction operator* (const Fraction &ref) const;
        Fraction operator/ (const Fraction &ref) const;
        bool operator== (const Fraction &ref) const;
        friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);
    private:
        int numerator;
        int denominator;

        void reduce();
};



