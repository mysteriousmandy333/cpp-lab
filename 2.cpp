#include <iostream>
using namespace std;

// Conversion rate constant
const double conversionRate = 101.36;

class NepaleseCurrency;

class USCurrency {
private:
    double dollars;

public:
    // Constructor to initialize the US dollars
    USCurrency(double d) : dollars(d) {}

    // Get the value of US dollars
    double getDollars() const {
        return dollars;
    }

    // Overload the relational operators to compare USCurrency with NepaleseCurrency
    bool operator==(const NepaleseCurrency& n) const;
    bool operator!=(const NepaleseCurrency& n) const;
    bool operator<(const NepaleseCurrency& n) const;
    bool operator>(const NepaleseCurrency& n) const;
    bool operator<=(const NepaleseCurrency& n) const;
    bool operator>=(const NepaleseCurrency& n) const;
};

class NepaleseCurrency {
private:
    double rupees;

public:
    // Constructor to initialize the Nepalese rupees
    NepaleseCurrency(double r) : rupees(r) {}

    // Get the value of Nepalese rupees
    double getRupees() const {
        return rupees;
    }

    // Overload the relational operators to compare NepaleseCurrency with USCurrency
    bool operator==(const USCurrency& u) const {
        return rupees == (u.getDollars() * conversionRate);
    }

    bool operator!=(const USCurrency& u) const {
        return !(*this == u);
    }

    bool operator<(const USCurrency& u) const {
        return rupees < (u.getDollars() * conversionRate);
    }

    bool operator>(const USCurrency& u) const {
        return rupees > (u.getDollars() * conversionRate);
    }

    bool operator<=(const USCurrency& u) const {
        return !(*this > u);
    }

    bool operator>=(const USCurrency& u) const {
        return !(*this < u);
    }
};

// Define the relational operators for USCurrency
bool USCurrency::operator==(const NepaleseCurrency& n) const {
    return dollars == (n.getRupees() / conversionRate);
}

bool USCurrency::operator!=(const NepaleseCurrency& n) const {
    return !(*this == n);
}

bool USCurrency::operator<(const NepaleseCurrency& n) const {
    return dollars < (n.getRupees() / conversionRate);
}

bool USCurrency::operator>(const NepaleseCurrency& n) const {
    return dollars > (n.getRupees() / conversionRate);
}

bool USCurrency::operator<=(const NepaleseCurrency& n) const {
    return !(*this > n);
}

bool USCurrency::operator>=(const NepaleseCurrency& n) const {
    return !(*this < n);
}

int main() {
    USCurrency usd(5);       // 5 US dollars
    NepaleseCurrency npr(600); // 600 Nepalese rupees

    // Display the comparisons
    cout << "Comparing 5 USD with 600 NPR:" << endl;

    if (usd == npr) {
        cout << "5 USD is equal to 600 NPR" << endl;
    } else if (usd != npr) {
        cout << "5 USD is not equal to 600 NPR" << endl;
    }

    if (usd < npr) {
        cout << "5 USD is less than 600 NPR" << endl;
    } else if (usd > npr) {
        cout << "5 USD is greater than 600 NPR" << endl;
    }

    if (usd <= npr) {
        cout << "5 USD is less than or equal to 600 NPR" << endl;
    } else if (usd >= npr) {
        cout << "5 USD is greater than or equal to 600 NPR" << endl;
    }

    return 0;
}
