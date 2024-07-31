#include <iostream>
#include <cmath>    // For sqrt(), atan2(), and M_PI
#include <iomanip>  // For std::setprecision
using namespace std;

class CartesianToPolarConverter {
private:
    double x;
    double y;

public:
    // Constructor to initialize x and y
    CartesianToPolarConverter(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Convert Cartesian coordinates to polar coordinates
    void convertToPolar() {
        double radius = sqrt(x * x + y * y);
        double angle = atan2(y, x);  // Angle in radians

        // Convert angle from radians to degrees
        double angleDegrees = angle * (180.0 / M_PI);

        // Output the result
        cout << fixed << setprecision(2);  // Set precision for radius and angle
        cout << "Polar Coordinates:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Angle (in degrees): " << angleDegrees << endl;
    }
};

int main() {
    double x, y;

    // Input Cartesian coordinates
    cout << "Enter the X coordinate: ";
    cin >> x;
    cout << "Enter the Y coordinate: ";
    cin >> y;

    // Create an instance of CartesianToPolarConverter
    CartesianToPolarConverter converter(x, y);
    converter.convertToPolar();  // Perform conversion and display the result

    return 0;
}
