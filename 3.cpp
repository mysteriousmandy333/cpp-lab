#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }


    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 2.0); 
    Complex c2(1.0, 7.0); 

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "Complex number 1: ";
    c1.display();
    cout << "Complex number 2: ";
    c2.display();

    cout << "Sum: ";
    sum.display();
    cout << "Difference: ";
    diff.display();
    cout << "Product: ";
    prod.display();
    cout << "Quotient: ";
    quot.display();

    return 0;
}

