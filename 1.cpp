#include <iostream>
using namespace std;

// class Number {
// private:
//     int a;
//     int b;

// public:

//     Number(int x, int y) : a(x), b(y) {}

//     void display() const {
//         cout << "a: " << a << ", b: " << b << endl;
//     }

//     friend void swapNumbers(Number& n);
// };

// void swapNumbers(Number& n) {
//     int temp = n.a;
//     n.a = n.b;
//     n.b = temp;
// }

// int main() {
//     Number n(5, 10);

//     cout << "Original numbers: ";
//     n.display();

//     swapNumbers(n);

//     cout << "Swapped numbers: ";
//     n.display();

//     return 0;
// }
class num
{
    int x;
    int y;

public:
    num(int a , int b):x(a),y(b){}
    
    void display(){
        cout<<"a :"<<x<<"\tb:"<<y<<endl;
    }
        friend void swap(num& t);
};
    void swap(num& t){
        int temp=t.x;
        t.x=t.y;
        t.y=temp;
    }

int main(){
    num n1(5,9);
    n1.display();

    swap(n1);
    n1.display();
}
