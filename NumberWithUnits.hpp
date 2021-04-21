#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel {

    class NumberWithUnits {
        public:
        string unit;
        double num;

        static void read_units(ifstream& units_file);
        NumberWithUnits(double num, const string& unit): num(num), unit(unit){}

        //arithmetic operators
        friend NumberWithUnits operator+(const NumberWithUnits& n1, double n2);
        friend NumberWithUnits operator+(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator+=(NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator-(const NumberWithUnits& num);
        friend NumberWithUnits operator-(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator-=(NumberWithUnits& n1, const NumberWithUnits& n2);

        friend NumberWithUnits operator++(NumberWithUnits& num);
        friend NumberWithUnits operator++(NumberWithUnits& num, int);
        friend NumberWithUnits operator--(NumberWithUnits& num);
        friend NumberWithUnits operator--(NumberWithUnits& num, int);

        friend bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2);

        friend NumberWithUnits operator*(const NumberWithUnits& n1, double n2);
        friend NumberWithUnits operator*(double n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator*=(NumberWithUnits& n1, double n2);
        friend NumberWithUnits operator*=(double n1, NumberWithUnits& n2);

        friend istream& operator>>(istream& is, NumberWithUnits& num);
        friend ostream& operator<<(ostream& os, const NumberWithUnits& num);
    };
}
