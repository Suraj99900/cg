


/* ----------------
Name :- Suraj Jaiswal

Roll no. :- 69

Lab_1
*/


#include <iostream>

using namespace std;


class Complex {
public:
    double real;
    double imag;

public:
    // Constructors
    Complex(){
        real = 0;
        imag = 0;
    }

    Complex(double r, double i){
        real = r;
        imag = i;
    }

    // Overloaded addition operator
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded multiplication operator
    Complex operator*( Complex& other){
        return Complex((real * other.real) - (imag * other.imag), (real * other.imag) + (imag * other.real));
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real value : ";
        is >> c.real;
        cout << "Enter imaginary value : ";
        is >> c.imag;
        return is;
    }
};

int main() {

    cout << "(2,3)"<<endl;
    cout << "(1,-1)"<<endl;
    Complex a(2, 3);
    Complex b(1, -1);

    Complex sum = a + b;
    Complex product = a * b;

    cout << "a + b = " << sum << endl;
    cout << "a * b = " << product << endl;

    return 0;
}
