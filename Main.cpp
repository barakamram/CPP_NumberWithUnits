#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace ariel;
ifstream units_file{"myUnits.txt"};
const double EPS = 0.0001;


int main() {
  NumberWithUnits::read_units(units_file);
  cout<< "Hello, welcome to my units calculator "<<'\n'<<endl;
  cout<< "you will not be able to convert units that are not from the same group"<<endl;
  cout<< "Example: you will not be able to convert Time-Units to Weight-Units or Distance-Units"<<endl;
  cout<<'\n'<< "Please insert 2 Numbers with units, Example: 2[m] 50[cm] "<<'\n'<<endl;
  NumberWithUnits a{0, "m"};
  NumberWithUnits b{0, "m"};
  cin>>a;
  cin>>b;
  if(!(a>=b||a<b)){return 0;}
  string op, choose;
  double n;
  cout<< "Press E to exit"<<endl;
  while(op != "E"){
      cout<<'\n'<<"choose operator: +, -, +=, -=, ++, --, *,*=, ==, !=, >, <, >=, <= "<<endl;
      cout<< "a = "<< a <<'\n'<<"b = "<< b <<endl;
      cin>>op;
      //__________________ +,- __________________//
      if(op=="+"){
        cout <<"a+b = "<< (a+b) <<'\n';
      }
      if(op=="-"){
        cout <<"a-b = "<< (a-b) <<'\n';
      }

      //__________________ +=,-= __________________//
      if(op=="+="){
        cout << "which number do you want to increase: a or b -> ";
        cin >> choose;
        if(choose=="a"){
          cout << (a+=b) <<'\n';
        }
        if(choose=="b"){
          cout << (b+=a) <<'\n';
        }
      }
      if(op=="-="){
        cout << "which number do you wantto decrease: a or b -> ";
        cin >> choose;
        if(choose=="a"){
          cout << (a-=b) <<'\n';
        }
        if(choose=="b"){
          cout << (b-=a) <<'\n';
        }
      }

      //__________________ ++,-- __________________//
      if(op=="++"){
        cout << "which number do you want to increase: a or b -> ";
        cin >> choose;
        if(choose=="a"){
          cout << ++a <<'\n';
        }
        if(choose=="b"){
          cout << ++b <<'\n';
        }
      }
      if(op=="--"){
        cout << "which number do you want to decrease: a or b -> ";
        cin >> choose;
        if(choose=="a"){
          cout << --a <<'\n';
        }
        if(choose=="b"){
          cout << --b <<'\n';
        }
      }

      //__________________ *,*= __________________//
      if(op=="*"){
        cout << "which number do you want to multiply: a or b -> ";
        cin>>choose;
        cout<< "please insert a number: " ;
        cin>>n;
        if(choose=="a"){
          cout << a*n <<'\n';
        }
        if(choose=="b"){
          cout << b*n <<'\n';
        }
      }
      if(op=="*="){
        cout << "which number do you want to multiply & change: a or b -> ";
        cin>>choose;
        cout<< "please insert a number: " ;
        cin>>n;
        if(choose=="a"){
          cout << (a*=n) <<'\n';
        }
        if(choose=="b"){
          cout << (b*=n) <<'\n';
        }
      }

      //__________________ ==? __________________//
      if(op=="=="){
        cout << boolalpha;
        cout <<"a==b ? "<< (a==b) <<'\n';
      }
      if(op=="!="){
        cout << boolalpha;
        cout <<"a!=b ? "<< (a!=b) <<'\n';
      }
      if(op=="<"){
        cout << boolalpha;
        cout <<"a<b ? "<< (a<b) <<'\n';
      }
      if(op=="<="){
        cout << boolalpha;
        cout <<"a<=b ? "<< (a<=b) <<'\n';
      }
      if(op==">"){
        cout << boolalpha;
        cout <<"a>b ? "<< (a>b) <<'\n';
      }
      if(op==">="){
        cout << boolalpha;
        cout <<"a>=b ? "<< (a>=b) <<'\n';
      }

  }
  return 0;
}
