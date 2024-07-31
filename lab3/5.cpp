#include <iostream>
#include <string>
#include <iomanip>  // For std::setfill and std::setw
using namespace std;

class TimeConverter {
private:
    int hour;
    int minute;
    int second;
    string period;  // "AM" or "PM"

public:
    // Constructor to initialize hour, minute, second, and period
    TimeConverter(int h, int m, int s, string p) : hour(h), minute(m), second(s), period(p) {}

    // Convert time from 12-hour format to 24-hour format
    void convertTo24HourFormat() {
        int hour24 = hour;

        if (period == "PM") {
            if (hour24 != 12) {
                hour24 += 12;  // Convert PM hour to 24-hour format
            }
        } else if (period == "AM") {
            if (hour24 == 12) {
                hour24 = 0;  // Midnight case
            }
        } else {
            cout << "Invalid period. Please enter AM or PM." << endl;
            return;
        }

        // Output the result
        cout << "24-hour format time: ";
        cout << setfill('0') << setw(2) << hour24 << ":" 
             << setw(2) << minute << ":" 
             << setw(2) << second << endl;
    }
};

int main() {
    int hour, minute, second;
    string period;

    // Input time in 12-hour format
    cout << "Enter the hour (12-hour format): ";
    cin >> hour;
    cout << "Enter the minute: ";
    cin >> minute;
    cout << "Enter the second: ";
    cin >> second;
    cout << "Enter the period (AM/PM): ";
    cin >> period;

    // Validate input
    if (hour < 1 || hour > 12 || minute < 0 || minute > 59 || second < 0 || second > 59 || (period != "AM" && period != "PM")) {
        cout << "Invalid time input. Please enter valid hour, minute, second, and period (AM/PM)." << endl;
        return 1;
    }

    // Create an instance of TimeConverter
    TimeConverter converter(hour, minute, second, period);
    converter.convertTo24HourFormat();  // Perform conversion and display the result

    return 0;
}
