#include <iostream>
#include <iomanip> // For std::setw and std::setfill
using namespace std;

class TIME {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper function to normalize time (ensure proper range of hours, minutes, seconds)
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            minutes -= (-seconds + 59) / 60;
            seconds = (seconds % 60 + 60) % 60;
        }
        
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            hours -= (-minutes + 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
        
        if (hours < 0) {
            hours = (hours % 24 + 24) % 24;
        } else if (hours >= 24) {
            hours %= 24;
        }
    }

public:
    // Constructor to initialize the object to zero
    TIME() : hours(0), minutes(0), seconds(0) {}

    // Constructor to initialize the object to some constant value
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Overload + operator to add two TIME objects
    TIME operator+(const TIME& other) const {
        return TIME(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    // Overload - operator to subtract two TIME objects
    TIME operator-(const TIME& other) const {
        return TIME(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
    }

    // Overload > operator to compare two TIME objects
    bool operator>(const TIME& other) const {
        if (hours > other.hours) return true;
        if (hours < other.hours) return false;
        if (minutes > other.minutes) return true;
        if (minutes < other.minutes) return false;
        return seconds > other.seconds;
    }

    // Member function to display time in HH:MM:SS format
    void display() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }
};

int main() {
    // Create TIME objects
    TIME t1(2, 45, 50);
    TIME t2(1, 30, 40);
    TIME t3 = t1 + t2;
    TIME t4 = t1 - t2;

    // Display results
    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();
    cout << "Time 3 (t1 + t2): ";
    t3.display();
    cout << "Time 4 (t1 - t2): ";
    t4.display();

    // Compare times
    if (t1 > t2) {
        cout << "Time 1 is greater than Time 2" << endl;
    } else {
        cout << "Time 1 is not greater than Time 2" << endl;
    }

    return 0;
}
