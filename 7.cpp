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
    // Default constructor
    TIME() : hours(0), minutes(0), seconds(0) {}

    // Constructor to initialize the object to specific values
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Overload << operator to display time in HH:MM:SS format
    friend ostream& operator<<(ostream& os, const TIME& t) {
        os << setw(2) << setfill('0') << t.hours << ":"
           << setw(2) << setfill('0') << t.minutes << ":"
           << setw(2) << setfill('0') << t.seconds;
        return os;
    }

    // Overload >> operator to input time in HH MM SS format
    friend istream& operator>>(istream& is, TIME& t) {
        is >> t.hours >> t.minutes >> t.seconds;
        t.normalize();
        return is;
    }
};

int main() {
    TIME t1, t2;

    // Input times
    cout << "Enter time 1 (HH MM SS): ";
    cin >> t1;
    cout << "Enter time 2 (HH MM SS): ";
    cin >> t2;

    // Display times
    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;

    return 0;
}
