#include <iostream>
using namespace std;

// // Conversion rate constant
// const double conversionRate = 101.36;

// class NepaleseCurrency;

// class USCurrency {
// private:
//     double dollars;

// public:
//     // Constructor to initialize the US dollars
//     USCurrency(double d) : dollars(d) {}

//     // Get the value of US dollars
//     double getDollars() const {
//         return dollars;
//     }

//     // Overload the relational operators to compare USCurrency with NepaleseCurrency
//     bool operator==(const NepaleseCurrency& n) const;
//     bool operator!=(const NepaleseCurrency& n) const;
//     bool operator<(const NepaleseCurrency& n) const;
//     bool operator>(const NepaleseCurrency& n) const;
//     bool operator<=(const NepaleseCurrency& n) const;
//     bool operator>=(const NepaleseCurrency& n) const;
// };

// class NepaleseCurrency {
// private:
//     double rupees;

// public:
//     // Constructor to initialize the Nepalese rupees
//     NepaleseCurrency(double r) : rupees(r) {}

//     // Get the value of Nepalese rupees
//     double getRupees() const {
//         return rupees;
//     }

//     // Overload the relational operators to compare NepaleseCurrency with USCurrency
//     bool operator==(const USCurrency& u) const {
//         return rupees == (u.getDollars() * conversionRate);
//     }

//     bool operator!=(const USCurrency& u) const {
//         return !(*this == u);
//     }

//     bool operator<(const USCurrency& u) const {
//         return rupees < (u.getDollars() * conversionRate);
//     }

//     bool operator>(const USCurrency& u) const {
//         return rupees > (u.getDollars() * conversionRate);
//     }

//     bool operator<=(const USCurrency& u) const {
//         return !(*this > u);
//     }

//     bool operator>=(const USCurrency& u) const {
//         return !(*this < u);
//     }
// };

// // Define the relational operators for USCurrency
// bool USCurrency::operator==(const NepaleseCurrency& n) const {
//     return dollars == (n.getRupees() / conversionRate);
// }

// bool USCurrency::operator!=(const NepaleseCurrency& n) const {
//     return !(*this == n);
// }

// bool USCurrency::operator<(const NepaleseCurrency& n) const {
//     return dollars < (n.getRupees() / conversionRate);
// }

// bool USCurrency::operator>(const NepaleseCurrency& n) const {
//     return dollars > (n.getRupees() / conversionRate);
// }

// bool USCurrency::operator<=(const NepaleseCurrency& n) const {
//     return !(*this > n);
// }

// bool USCurrency::operator>=(const NepaleseCurrency& n) const {
//     return !(*this < n);
// }

// int main() {
//     USCurrency usd(5);       // 5 US dollars
//     NepaleseCurrency npr(600); // 600 Nepalese rupees

//     // Display the comparisons
//     cout << "Comparing 5 USD with 600 NPR:" << endl;

//     if (usd == npr) {
//         cout << "5 USD is equal to 600 NPR" << endl;
//     } else if (usd != npr) {
//         cout << "5 USD is not equal to 600 NPR" << endl;
//     }

//     if (usd < npr) {
//         cout << "5 USD is less than 600 NPR" << endl;
//     } else if (usd > npr) {
//         cout << "5 USD is greater than 600 NPR" << endl;
//     }

//     if (usd <= npr) {
//         cout << "5 USD is less than or equal to 600 NPR" << endl;
//     } else if (usd >= npr) {
//         cout << "5 USD is greater than or equal to 600 NPR" << endl;
//     }

//     return 0;
// }
const double rate = 101.36;
class usd;
class npr{
    double ruppe;
    public:
    npr(float n):ruppe(n){}
    float getnpr(){
        return ruppe;
    }
    bool operator==(usd t);
    bool operator>(usd t);
    bool operator<(usd t);
    bool operator<=(usd t);
    bool operator>=(usd t);
};

class usd{
    double dollars;
    public:
    usd(float n):dollars(n){}

    float getusd(){
        return dollars;
    }

    bool operator==(npr t){
        return (dollars ==t.getnpr()/rate);
    }
    bool operator<=(npr t){
        return (dollars <=t.getnpr()/rate);

    }
    bool operator>=(npr t){
        return (dollars >=t.getnpr()/rate);

    }
    bool operator>(npr t){
        return (dollars >t.getnpr()/rate);

    }
    bool operator<(npr t){
        return (dollars <t.getnpr()/rate);

    }
};

bool npr::operator==(usd t){
    return(ruppe==t.getusd()*rate);
}
bool npr::operator<=(usd t){
    return(ruppe<=t.getusd()*rate);

}
bool npr::operator>=(usd t){
    return(ruppe>=t.getusd()*rate);

}
bool npr::operator<(usd t){
    return(ruppe<t.getusd()*rate);

}
bool npr::operator>(usd t){
    return(ruppe>t.getusd()*rate);

}

int main (){
    npr rupaiya(1500);
    usd dolar(14);

    if (rupaiya==dolar){
        cout<<"Barabar xa ";
    }
    if (rupaiya<dolar){
        cout<<"DOlar ko bhau Badhyo "<<endl;
    }
    else if (rupaiya>dolar){
        cout<<"Nepali rupe nei Dher xa "<<endl;
    }
    if (rupaiya<=dolar){
        cout<<"Dolar ya tw dher xa ya tw barabar xa "<<endl;
    }
    else if(rupaiya>=dolar )
    {
        cout<<"Rupaiya  ya tw dher xa ya tw barabar xa  "<<endl;
    }
}