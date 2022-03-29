#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"
Fraction::~Fraction(){
    removedFractions_++;
}

int Fraction::getNumerator() const {
    return numerator;
}
int Fraction::getDenominator() const {
    return denominator;
}
std::string Fraction::getFractionName() const {
    return fractionName;
}
void Fraction::setNumerator(int x) {
    this->numerator = x;
}
void Fraction::setDenominator(int y) {
    this->denominator= y;
}
int Fraction::removedFractions()  {
    return removedFractions_;
}
int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}
void Fraction::print() const {
    std::cout << numerator << "/" << denominator << std::endl; // albo printf("%f/%f\n", numerator, denominator);
}
void Fraction::save(std::ostream &os) const {
    os << numerator << "/" << denominator;
}
void Fraction::load(std::istream &is) {
    std::string n,d;
    std::getline(is, n, '/');
    std::getline(is, d, '/');
    this->numerator = std::stoi(n);
    this->denominator = std::stoi(d);
}

int Fraction::removedFractions_;

#if !IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists

