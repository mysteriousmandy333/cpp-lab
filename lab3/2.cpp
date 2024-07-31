#include <iostream>
#include <cmath>    // For sin(), cos(), and M_PI
#include <iomanip>  // For std::setprecision
using namespace std;

class PolarToCartesianConverter {
private:
    double radius;
    double angle; // Angle in radians

public:
    // Constructor to initialize radius and angle
    PolarToCartesianConverter(double r, double a) : radius(r), angle(a) {}

    // Convert polar coordinates to Cartesian coordinates
    void convertToCartesian() {
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        // Output the result
        cout << fixed << setprecision(2);  // Set precision for coordinates
        cout << "Cartesian Coordinates:" << endl;
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
};

int main() {
    double radius, angleDegrees;

    // Input radius and angle in degrees
    cout << "Enter the radius: ";
    cin >> radius;
    cout << "Enter the angle in degrees: ";
    cin >> angleDegrees;

    // Convert angle to radians
    double angleRadians = angleDegrees * (M_PI / 180.0);

    // Create an instance of PolarToCartesianConverter
    PolarToCartesianConverter converter(radius, angleRadians);
    converter.convertToCartesian();  // Perform conversion and display the result

    return 0;
}
