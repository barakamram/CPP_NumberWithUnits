#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("calculator") {
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

  NumberWithUnits num{1, "m"};
  CHECK((num++) == NumberWithUnits(1,"m"));
  CHECK((++num) == NumberWithUnits(2,"m"));
  CHECK(num == NumberWithUnits(3,"m"));
  CHECK((num--)== NumberWithUnits(3,"m"));
  CHECK(num == NumberWithUnits(2,"m"));
  CHECK((--num)== NumberWithUnits(1,"m"));

  NumberWithUnits n1{10,"m"};
  NumberWithUnits n2{10,"m"};
  CHECK((n1 + n2) == NumberWithUnits(20,"m"));
  CHECK((n1 - n2) == NumberWithUnits(0,"m"));
  CHECK((n1 += n2) == NumberWithUnits(20,"m"));
  CHECK(n1 == NumberWithUnits{20,"m"});
  CHECK((n1 + n2) == NumberWithUnits(30,"m"));
  CHECK((n1*10) == NumberWithUnits(200,"m"));
  CHECK((n2*=2)==NumberWithUnits(20,"m"));
  //n1.num == 20, n2.num == 20
  CHECK_EQ(n1 > n2, false);
  CHECK_EQ(n1 < n2, false);
  CHECK_EQ(n1 != n2, false);
  CHECK_EQ(n1 >= n2, true);
  CHECK_EQ(n1 <= n2, true);
  CHECK_EQ(n1 == n2, true);
}

TEST_CASE("illegel input") {
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

  CHECK_THROWS(NumberWithUnits km(1, "KM"));
  CHECK_THROWS(NumberWithUnits m(1,"M"));
  CHECK_THROWS(NumberWithUnits cm(1,"cM"));

  CHECK_THROWS(NumberWithUnits kg(1,"Kg"));
  CHECK_THROWS(NumberWithUnits g(1,"G"));
  CHECK_THROWS(NumberWithUnits ton(1,"tON"));

  CHECK_THROWS(NumberWithUnits hour(1,"HOUR"));
  CHECK_THROWS(NumberWithUnits min(1,"MiN"));
  CHECK_THROWS(NumberWithUnits sec(1,"sEC"));

  CHECK_THROWS(NumberWithUnits USD(1,"UsD"));
  CHECK_THROWS(NumberWithUnits ILS(1,"Ils"));
}
