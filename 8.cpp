#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

class ParkingGarage {
private:
    static int carCount;
    tm entryTime;
    tm exitTime;
    double charge;

public:
    ParkingGarage() {
        carCount++;
    }

    ~ParkingGarage() {
        carCount--;
    }

    // Function to set entry time
    void setEntryTime(int year, int month, int day, int hour, int minute) {
        entryTime = { 0 };
        entryTime.tm_year = year - 1900;
        entryTime.tm_mon = month - 1;
        entryTime.tm_mday = day;
        entryTime.tm_hour = hour;
        entryTime.tm_min = minute;
    }

    // Function to set exit time
    void setExitTime(int year, int month, int day, int hour, int minute) {
        exitTime = { 0 };
        exitTime.tm_year = year - 1900;
        exitTime.tm_mon = month - 1;
        exitTime.tm_mday = day;
        exitTime.tm_hour = hour;
        exitTime.tm_min = minute;
    }

    // Function to calculate parking fee
    double calculateFee() {
        double totalHours = difftime(mktime(&exitTime), mktime(&entryTime)) / 3600.0;
        double fee = 0.0;

        if (totalHours <= 3) {
            fee = 2.00;
        } else {
            totalHours -= 3;
            fee = 2.00 + (0.50 * ((int)ceil(totalHours)));
        }

        if (totalHours > 24) {
            fee = 8.00 * (int)(totalHours / 24);
            if (static_cast<int>(totalHours) % 24 != 0) {
                fee += 8.00;
            }
        }

        return fee;
    }

    // Overloading ++ and -- operators to manage car count
    static void incrementCarCount() {
        carCount++;
    }

    static void decrementCarCount() {
        carCount--;
    }

    static int getCarCount() {
        return carCount;
    }

    // Function to display the details
    void display() {
        cout << "Entry Time: " << put_time(&entryTime, "%Y-%m-%d %H:%M") << endl;
        cout << "Exit Time: " << put_time(&exitTime, "%Y-%m-%d %H:%M") << endl;
        cout << "Parking Fee: $" << fixed << setprecision(2) << calculateFee() << endl;
    }
};

int ParkingGarage::carCount = 0;

int main() {
    ParkingGarage car1, car2;

    // Set entry and exit times for car1
    car1.setEntryTime(2024, 7, 30, 10, 0);
    car1.setExitTime(2024, 7, 31, 12, 0);

    // Set entry and exit times for car2
    car2.setEntryTime(2024, 7, 30, 15, 0);
    car2.setExitTime(2024, 7, 31, 18, 0);

    // Display parking details
    cout << "Car 1 Details:" << endl;
    car1.display();
    cout << endl;

    cout << "Car 2 Details:" << endl;
    car2.display();
    cout << endl;

    // Display current number of cars in the garage
    cout << "Number of cars in the garage: " << ParkingGarage::getCarCount() << endl;

    return 0;
}
