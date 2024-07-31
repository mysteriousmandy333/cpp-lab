#include <iostream>
#include <cstring> // For strlen, strcpy, strcat, strcmp
using namespace std;

const int MAX_LENGTH = 100;

class STRING {
private:
    char str[MAX_LENGTH];
    int length;

public:
    // Default constructor
    STRING() : length(0) {
        str[0] = '\0';
    }

    // Constructor to initialize the object with a C-string
    STRING(const char* s) {
        length = strlen(s);
        if (length < MAX_LENGTH) {
            strcpy(str, s);
        } else {
            strncpy(str, s, MAX_LENGTH - 1);
            str[MAX_LENGTH - 1] = '\0';
            length = MAX_LENGTH - 1;
        }
    }

    // Overload the + operator for string concatenation
    STRING operator+(const STRING& other) const {
        STRING temp;
        temp.length = length + other.length;
        if (temp.length < MAX_LENGTH) {
            strcpy(temp.str, str);
            strcat(temp.str, other.str);
        } else {
            if (length < MAX_LENGTH) {
                strncpy(temp.str, str, length);
                strncpy(temp.str + length, other.str, MAX_LENGTH - length - 1);
                temp.str[MAX_LENGTH - 1] = '\0';
            }
            temp.length = MAX_LENGTH - 1;
        }
        return temp;
    }

    // Overload the = operator for string assignment
    STRING& operator=(const STRING& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }
        length = other.length;
        if (length < MAX_LENGTH) {
            strcpy(str, other.str);
        } else {
            strncpy(str, other.str, MAX_LENGTH - 1);
            str[MAX_LENGTH - 1] = '\0';
            length = MAX_LENGTH - 1;
        }
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
