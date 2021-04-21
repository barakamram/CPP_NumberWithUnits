#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel{

    void NumberWithUnits::read_units(ifstream& units_file){}

    NumberWithUnits operator+(const NumberWithUnits& n1, double n2){
        return n1;
    }
    NumberWithUnits operator+(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return n1;
    }
    NumberWithUnits operator+=(NumberWithUnits& n1, const NumberWithUnits& n2){
        return n1;
    }
    NumberWithUnits operator-(const NumberWithUnits& num){
        return num;
    }
    NumberWithUnits operator-(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return n1;
    }
    NumberWithUnits operator-=(NumberWithUnits& n1, const NumberWithUnits& n2){
        return n1;
    }

    NumberWithUnits operator++(NumberWithUnits& num){
        return num;
    }
    NumberWithUnits operator++(NumberWithUnits& num, int){
        return num;
    }
    NumberWithUnits operator--(NumberWithUnits& num){
        return num;
    }
    NumberWithUnits operator--(NumberWithUnits& num, int){
        return num;
    }

    bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }
    bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }
    bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }
    bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }
    bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }
    bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2){ return false; }

    NumberWithUnits operator*(const NumberWithUnits& n1, double n2){
        return n1;
    }
    NumberWithUnits operator*(double n2, const NumberWithUnits& n1){
        return n1;
    }
    NumberWithUnits operator*=(NumberWithUnits& n1, double n2){
        return n1;
    }
    NumberWithUnits operator*=(double n2, NumberWithUnits& n1){
        return n1;
    }

    istream& operator>>(istream& is, NumberWithUnits& num){
        return is;
    }
    ostream& operator<<(ostream& os, const NumberWithUnits& num){
        return os;
    }
}
