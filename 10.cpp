#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor
    Rectangle(int w = 0, int h = 0) : width(w), height(h) {}

    // Member function to set dimensions
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }

    // Member function to display dimensions
    void display() const {
        cout << "Width: " << width << ", Height: " << height << endl;
    }

    // Member function to calculate area
    int area() const {
        return width * height;
    }

    // Friend function to overload + operator
    friend Rectangle operator+(const Rectangle& rect1, const Rectangle& rect2);

    // Friend function to overload << operator
    friend ostream& operator<<(ostream& os, const Rectangle& rect);

    // Friend function to overload >> operator
    friend istream& operator>>(istream& is, Rectangle& rect);
};

// Overload + operator to add two Rectangle objects
Rectangle operator+(const Rectangle& rect1, const Rectangle& rect2) {
    return Rectangle(rect1.width + rect2.width, rect1.height + rect2.height);
}

// Overload << operator to display the rectangle
ostream& operator<<(ostream& os, const Rectangle& rect) {
    os << "Width: " << rect.width << ", Height: " << rect.height;
    return os;
}

// Overload >> operator to input rectangle dimensions
istream& operator>>(istream& is, Rectangle& rect) {
    is >> rect.width >> rect.height;
    return is;
}

int main() {
    Rectangle rect1(10, 5), rect2(3, 2);

    cout << "Rectangle 1: " << rect1 << endl;
    cout << "Rectangle 2: " << rect2 << endl;

    Rectangle rect3 = rect1 + rect2;
    cout << "Rectangle 3 (result of addition): " << rect3 << endl;

    return 0;
}
