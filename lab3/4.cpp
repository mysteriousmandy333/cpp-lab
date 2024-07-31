#include <iostream>
#include <iomanip>  // For std::setfill and std::setw
using namespace std;

class TimeConverter {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor to initialize hour, minute, and second
    TimeConverter(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Convert time from 24-hour format to 12-hour format
    void convertTo12HourFormat() {
        string period = "AM";
        int hour12 = hour;

        // Determine period and adjust hour
        if (hour == 0) {
            hour12 = 12;  // Midnight case
        } else if (hour == 12) {
            period = "PM";  // Noon case
        } else if (hour > 12) {
            hour12 = hour - 12;  // PM case
            period = "PM";
        }

        // Output the result
        cout << "12-hour format time: ";
        cout << setfill('0') << setw(2) << hour12 << ":" 
             << setw(2) << minute << ":" 
             << setw(2) << second << " " 
             << period << endl;
    }
};

int main() {
    int hour, minute, second;

    // Input time in 24-hour format
    cout << "Enter the hour (24-hour format): ";
    cin >> hour;
    cout << "Enter the minute: ";
    cin >> minute;
    cout << "Enter the second: ";
    cin >> second;

    // Validate input
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        cout << "Invalid time input. Please enter valid hour, minute, and second." << endl;
        return 1;
    }

    // Create an instance of TimeConverter
    TimeConverter converter(hour, minute, second);
    converter.convertTo12HourFormat();  // Perform conversion and display the result

    return 0;
}
