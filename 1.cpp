#include <iostream>
using namespace std;

class Number {
private:
    int a;
    int b;

public:
    
    Number(int x, int y) : a(x), b(y) {}

   
    void display() const {
        cout << "a: " << a << ", b: " << b << endl;
    }

    
    friend void swapNumbers(Number& n);
};


void swapNumbers(Number& n) {
    int temp = n.a;
    n.a = n.b;
    n.b = temp;
}

int main() {
    Number n(5, 10);

    cout << "Original numbers: ";
    n.display();

    
    swapNumbers(n);

    
    cout << "Swapped numbers: ";
    n.display();

    return 0;
}
