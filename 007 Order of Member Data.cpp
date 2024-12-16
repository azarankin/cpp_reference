/***
 * Order of Member Data
 */

#include <iostream>
#include <string>

struct Widget1 
{
  bool b1;  //char padding1[3];
  double d;   // Needs to be 4-byte aligned on x64
  bool b2;  //char padding2[3];
};


struct Widget2 
{
  bool b1;  //char padding1[7];
  double d;   // Needs to be 8-byte aligned on x64
  bool b2;  //char padding2[7];
};


struct Widget3 //Pay attention when designing classes
{
  double d; // Largest first
  bool b1;
  bool b2;  //char padding[6];
};

struct Widget4
{
  std::string s; // Asdsumption: consumes 24 bytes, count by alighments (3 ptr of bytes)
  bool b1;
  bool b2;  //char padding[6];
};

//puts the padding to the end of the class as possible


int main() 
{
  std::cout << sizeof(Widget1) << '\n';   // prints 12
  std::cout << sizeof(Widget2) << '\n';   // prints 24
  std::cout << sizeof(Widget3) << '\n';   // prints 16

  std::cout << sizeof(Widget3) << '\n';   // prints 32
  return 0;
}