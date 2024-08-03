#include <iostream>
using namespace std;

// class Complex {
// private:
//     double real;
//     double imag;

// public:
    
//     Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


//     Complex operator+(const Complex& other) const {
//         return Complex(real + other.real, imag + other.imag);
//     }


//     Complex operator-(const Complex& other) const {
//         return Complex(real - other.real, imag - other.imag);
//     }

//     Complex operator*(const Complex& other) const {
//         return Complex(real * other.real - imag * other.imag,
//                        real * other.imag + imag * other.real);
//     }
//     Complex operator/(const Complex& other) const {
//         double denominator = other.real * other.real + other.imag * other.imag;
//         return Complex((real * other.real + imag * other.imag) / denominator,
//                        (imag * other.real - real * other.imag) / denominator);
//     }

//     void display() const {
//         if (imag >= 0)
//             cout << real << " + " << imag << "i" << endl;
//         else
//             cout << real << " - " << -imag << "i" << endl;
//     }
// };

// int main() {
//     Complex c1(3.0, 2.0); 
//     Complex c2(1.0, 7.0); 

//     Complex sum = c1 + c2;
//     Complex diff = c1 - c2;
//     Complex prod = c1 * c2;
//     Complex quot = c1 / c2;

//     cout << "Complex number 1: ";
//     c1.display();
//     cout << "Complex number 2: ";
//     c2.display();

//     cout << "Sum: ";
//     sum.display();
//     cout << "Difference: ";
//     diff.display();
//     cout << "Product: ";
//     prod.display();
//     cout << "Quotient: ";
//     quot.display();

//     return 0;
// }

class complex{
    double re;
    double img;
    public:
    complex(double a=0.0, double b=0.0):re(a),img(b){}

    void display(){
        cout<< re ;
        if (img<0)
        {
            cout<<"\t-j"<<img<<endl;
        }
        else{
            cout<<"\t+j"<<img<<endl;
        }
        
    }
 
    complex operator+(complex t){
        return complex(re+t.re , img+t.img);
    }
    complex operator-(complex t){
        return complex(re-t.re , img-t.img);
    }
    complex operator*(complex t){
        return complex(re*t.re - img*t.img, img*t.re+re*t.img);
    }
    // complex operator+(complex t){
    //     return complex(re+t.re , img+t.img);
    // }
};
int main(){
    complex c1(4,5);
    complex c2(5,5);
    c1.display();
complex c3;
c3=c1+c2;
c3.display();

}