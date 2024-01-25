#include <iostream>

class Fraction {
    int total;
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) {
        this->total = num / denom;
        this->numerator = num % denom;
        this->denominator = denom;
    }
    void setNumerator(int n) {
        this->total = n / denominator;
        this->numerator = n % denominator;
    }
    void setDenominator(int n) {
        if (n == 0) return;
        denominator = n;
        this->total = total / denominator;
        this->numerator = numerator % denominator;
    }
    void show() {
        std::cout << total << " " << numerator << "/" << denominator << std::endl;
    }
    Fraction sum(Fraction f2) {
        int num;
        num = this->numerator * f2.denominator + f2.numerator * this->denominator
            + this->total * this->denominator * f2.denominator + f2.total * this->denominator * f2.denominator;
        int denum = this->denominator * f2.denominator;
        return Fraction(num, denum);
    }
    Fraction operator+(const Fraction& f2) {
        int num = this->numerator * f2.denominator + f2.numerator * this->denominator
            + this->total * this->denominator * f2.denominator + f2.total * this->denominator * f2.denominator;
        int denum = this->denominator * f2.denominator;
        return Fraction(num, denum);
    }
    Fraction operator-(const Fraction& f2) {
        int num = this->numerator * f2.denominator - f2.numerator * this->denominator
            + this->total * this->denominator * f2.denominator - f2.total * this->denominator * f2.denominator;
        int denum = this->denominator * f2.denominator;
        return Fraction(num, denum);
    }
    Fraction operator*(const Fraction& f2) {
        int num = (this->total * this->denominator + this->numerator) * (f2.total * f2.denominator + f2.numerator);
        int denum = this->denominator * f2.denominator;
        return Fraction(num, denum);
    }
    Fraction operator/(const Fraction& f2) {
        int num = (this->total * this->denominator + this->numerator) * f2.denominator;
        int denum = this->denominator * (f2.total * f2.denominator + f2.numerator);
        return Fraction(num, denum);
    }
    bool operator>(Fraction f2) {
        if (this->total > f2.total) return true;
        if (this->total < f2.total) return false;
        if (this->numerator * f2.denominator > f2.numerator * this->denominator) return true;
        return false;
    }
    Fraction operator%(Fraction f2) {
        Fraction f1 = *this;
        while ((f1 - f2) > Fraction(0, 1))
            f1 = f1 - f2;
        return f1;
    }
};

int main() {
    Fraction f(6, 1);
    f.show();
    Fraction result = f.sum(Fraction(5, 2));
    result.show();
    result = result + f;
    result.show();
    result = result - f;
    result.show();
    result = result * f;
    result.show();
    result = result / Fraction(2,3);
    result.show();
    result = result % f;
    result.show();
}