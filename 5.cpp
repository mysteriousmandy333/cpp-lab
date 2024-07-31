#include <iostream>
#include <cstring> // For strlen, strcpy, strcat
using namespace std;

class STRING {
private:
    char* str;
    int length;

public:
    // Default constructor
    STRING() : str(nullptr), length(0) {}

    // Constructor to initialize the object with a C-string
    STRING(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy constructor
    STRING(const STRING& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~STRING() {
        delete[] str;
    }

    // Overload the + operator for string concatenation
    STRING operator+(const STRING& other) const {
        STRING temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    // Overload the = operator for string assignment
    STRING& operator=(const STRING& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }
        delete[] str; // Free the existing memory
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return *this;
    }

    // Overload the == operator for string comparison
    bool operator==(const STRING& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    // Creating STRING objects
    STRING s1("Hello, ");
    STRING s2("World!");

    // Concatenating strings
    STRING s3 = s1 + s2;

    // Displaying concatenated string
    cout << "Concatenated String: ";
    s3.display();

    // Assigning one string to another
    STRING s4;
    s4 = s1;

    // Displaying assigned string
    cout << "Assigned String: ";
    s4.display();

    // Comparing strings
    if (s1 == s4) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }

    return 0;
}
