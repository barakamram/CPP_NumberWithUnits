#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
const double EPS = 0.0001;
using namespace std;

namespace ariel{

    static unordered_map<string, unordered_map<string, double>> list;

    // Constructor - checking if the unit exist in the map
    NumberWithUnits::NumberWithUnits(double value, const string& unit) {
      if(list.count(unit) == 0){
        throw invalid_argument("invalid type of unit");
      }
      this-> value = value;
      this-> unit = unit;
    }

    // Helper function that doing convertion between units
    double convert(double value, const string& from, const string& to){
        if (from == to){
          return value;
        }
        if(list[from][to] == 0){
          throw invalid_argument("["+from+"] cannot be converted to ["+to+"]");
        }
        return value * list[from][to];
    }
    void NumberWithUnits::read_units(ifstream& units_file){
        double fromVal = 0, toVal = 0;
        string fromUnit, toUnit, sign;
        while(units_file >> fromVal >> fromUnit >> sign >> toVal >> toUnit){
          list[fromUnit][toUnit] = toVal;
          list[toUnit][fromUnit] = 1/toVal;
          for(const auto& p: list[fromUnit]){
            list[toUnit][p.first] = list[toUnit][fromUnit] * p.second;
            list[p.first][toUnit] = 1/(list[toUnit][fromUnit] * p.second);
          }
          for(const auto& p: list[toUnit]){
            list[fromUnit][p.first] = list[fromUnit][toUnit] * p.second;
            list[p.first][fromUnit] = 1/(list[fromUnit][toUnit] * p.second);
          }
        }
    }

    //______________ + - ______________//
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& n) const{
      double amount = convert(n.value,n.unit,unit);
      return NumberWithUnits(value + amount,unit);
    }
    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& n) const{
      double amount = convert(n.value,n.unit,unit);
      return NumberWithUnits(value - amount,unit);
    }
    NumberWithUnits NumberWithUnits::operator+() {
      return NumberWithUnits(value,unit);
    }
    NumberWithUnits NumberWithUnits::operator-() {
      return NumberWithUnits(-value,unit);
    }
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& n){
      double amount = convert(n.value,n.unit,unit);
      value += amount;
      return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& n){
      double amount = convert(n.value,n.unit,unit);
      value -= amount;
      return *this;
    }

    //______________ ++ -- ______________//
    NumberWithUnits& NumberWithUnits::operator++(){
      ++value;
      return *this;
    }
    NumberWithUnits& NumberWithUnits::operator--(){
      --value;
      return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){
      return NumberWithUnits(value++,unit);
    }
    NumberWithUnits NumberWithUnits::operator--(int){
      return NumberWithUnits(value--,unit);
    }

    //______________ * ______________//
    NumberWithUnits NumberWithUnits::operator*(double d) const{
      return d*(*this);
    }
    NumberWithUnits operator*(double d, const NumberWithUnits& n){
      return NumberWithUnits(d * n.value, n.unit);
    }

    //______________ == ______________//
    bool NumberWithUnits::operator>(const NumberWithUnits& n) const{
      double amount = convert(n.value,n.unit,unit);
      return value > amount;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits& n) const{
      double amount = convert(n.value,n.unit,unit);
      return value < amount;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits& n) const{
      return ((*this > n) || (*this == n));
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits& n) const{
      return !(*this > n);
    }
    bool NumberWithUnits::operator==(const NumberWithUnits& n) const{
      double amount = convert(n.value,n.unit,unit);
      return (abs(value-amount) <= EPS);
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits& n) const{
      return !(*this == n);
    }

    //______________ in & out ______________//
    istream& operator>>(istream& is, NumberWithUnits& n){
      string unit_type;
      double unit_value = 0;
      char in = ' ';
      is >> unit_value;
      is >> in;
      while(in!=']'){
        if(in!='['){
          unit_type+=in;
        }
        is >> in;
      }
      if(list.count(unit_type)==0){
        throw invalid_argument("invalid type of unit");
      }
      n = NumberWithUnits(unit_value, unit_type);
      return is;
    }
    ostream& operator<<(ostream& os, const NumberWithUnits& n){
      os << n.value << "[" << n.unit << "]";
      return os;
    }
};
