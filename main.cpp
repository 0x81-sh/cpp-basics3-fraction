#include <cassert>
#include <iostream>
#include "Fraction.h"

void test_mul(const Fraction &a, const Fraction &b, const Fraction &res);
void test_div(const Fraction &a, const Fraction &b, const Fraction &res);
void test_cmp(const Fraction &a, const Fraction &b);
void test_reduce(const Fraction &a, const Fraction &b);

int main() {
    test_mul(Fraction(1, 23), Fraction(7, 3), Fraction(7, 69));
    test_mul(Fraction(23, 3), Fraction(3, 7), Fraction(23, 7));

    test_div(Fraction(1, 23), Fraction(7, 3), Fraction(3, 161));
    test_div(Fraction(23, 3), Fraction(3, 7), Fraction(161, 9));

    test_cmp(Fraction(1, 4), Fraction(1 ,4));
    test_reduce(Fraction(26, 2), Fraction(13, 1));

    return 0;
}

void test_mul(const Fraction &a, const Fraction &b, const Fraction &res) {
    assert(a.mul(b).equal(res));
}

void test_div(const Fraction &a, const Fraction &b, const Fraction &res) {
    assert(a.div(b).equal(res));
}

void test_cmp(const Fraction &a, const Fraction &b) {
    assert(a.equal(b));
}

void test_reduce(const Fraction &a, const Fraction &b) {
    assert(a.equal(b));
}