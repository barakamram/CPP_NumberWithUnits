#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
namespace ariel {
    class NumberWithUnits {
    public:
        string unit;
        double value;
        NumberWithUnits(double value, const string& unit);
        static void read_units(ifstream& units_file);

        //______________ + - ______________//
        NumberWithUnits operator+(const NumberWithUnits& n) const;
        NumberWithUnits operator-(const NumberWithUnits& n) const;
        NumberWithUnits operator+();
        NumberWithUnits operator-();
        NumberWithUnits& operator+=(const NumberWithUnits& n);
        NumberWithUnits& operator-=(const NumberWithUnits& n);

        //______________ ++ -- ______________//
        NumberWithUnits& operator++();
        NumberWithUnits& operator--();
        NumberWithUnits operator++(int);
        NumberWithUnits operator--(int);

        //______________ * *= ______________//
        NumberWithUnits operator*(double d) const;
        friend NumberWithUnits operator*(double d, const NumberWithUnits& n);
        NumberWithUnits operator*=(double d);

        //______________ == ______________//
        bool operator>(const NumberWithUnits& n) const;
        bool operator<(const NumberWithUnits& n) const;
        bool operator>=(const NumberWithUnits& n) const;
        bool operator<=(const NumberWithUnits& n) const;
        bool operator==(const NumberWithUnits& n) const;
        bool operator!=(const NumberWithUnits& n) const;

        //______________ in & out ______________//
        friend istream& operator>>(istream& is, NumberWithUnits& n);
        friend ostream& operator<<(ostream& os, const NumberWithUnits& n);
    };
}
