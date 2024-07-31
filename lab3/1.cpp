#include <iostream>
#include <iomanip>  // For std::setprecision and std::setw
using namespace std;

class CurrencyConverter {
private:
    double rupees;
    double paisa;
    const double conversionRate = 98.51;  // Conversion rate from NPR to USD

public:
    // Constructor to initialize rupees and paisa
    CurrencyConverter(double r, double p) : rupees(r), paisa(p) {}

    // Convert the amount to USD
    void convertToUSD() {
        double totalRupees = rupees + paisa / 100.0;
        double dollars = totalRupees / conversionRate;

        int dollarAmount = static_cast<int>(dollars);
        int centAmount = static_cast<int>((dollars - dollarAmount) * 100);

        // Output the result
        cout << fixed << setprecision(2);  // Set precision for dollars and cents
        cout << "Equivalent amount in USD: $" << dollarAmount << "." 
             << setw(2) << setfill('0') << centAmount << endl;
    }
};

int main() {
    double rupees, paisa;

    // Input Rupees and Paisa
    cout << "Enter the amount in Rupees: ";
    cin >> rupees;
    cout << "Enter the amount in Paisa: ";
    cin >> paisa;

    // Create an instance of CurrencyConverter
    CurrencyConverter converter(rupees, paisa);
    converter.convertToUSD();  // Perform conversion and display the result

    return 0;
}
