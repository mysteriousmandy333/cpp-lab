#include <iostream>
using namespace std;

class Number {
private:
    int a;
    int b;

public:
    // Constructor to initialize the numbers
    Number(int x, int y) : a(x), b(y) {}

    // Function to display the numbers
    void display() const {
        cout << "a: " << a << ", b: " << b << endl;
    }

    // Friend function to swap the numbers
    friend void swapNumbers(Number& n);
};

// Friend function definition
void swapNumbers(Number& n) {
    int temp = n.a;
    n.a = n.b;
    n.b = temp;
}

int main() {
    // Create a Number object
    Number n(5, 10);

    // Display original numbers
    cout << "Original numbers: ";
    n.display();

    // Swap the numbers using the friend function
    swapNumbers(n);

    // Display swapped numbers
    cout << "Swapped numbers: ";
    n.display();

    return 0;
}
