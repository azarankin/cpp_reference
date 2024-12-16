/***
 * Implicit Conversion
 */

#include <cstdio>


class Widget
{
public:
  explicit Widget( int ) { std::puts( "Widget(int)" ); }
  Widget( int ) { std::puts( "Widget(int)" ); } //implicit
  // ...
};

void f( Widget ){};

int main()
{
  f( 42 ); //cant allowed implicit
  f( Widget(42) );

  return 0;
}