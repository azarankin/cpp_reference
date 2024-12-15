#include<string>



struct Widget
{
 int i;  // Uninitialized
 std::string s;  // Default-initialized
 int* pi;  // Uninitialized and problematic
};

struct Widget2
{
 int i;  // Initialized to 0
 std::string s;  // Default-initialized
 int* pi;  // Uninitialized and problematic
};

struct Widget3
{
 Widget3() {}  // Explicit default constructor
 int i;   // Uninitialized
 std::string s;   // Default (i.e., empty string)
 int* pi;   // Uninitialized
};



int main()
{
 Widget w;   // Default initialization
 Widget2 w2{};   // Value initialization
 Widget3 w3{};   // Value initialization
}



//less reccomended
struct Widget4
{
  Widget4()
  {
  i = 42;  // Assignment, not initialization
  s = "CppCon";  // Assignment, not initialization
  pi = nullptr;  // Assignment, not initialization
  }

  int i;
  std::string s;
  int* pi;
};


//
struct Widget5
{
  Widget5()
  : Widget5(42) // apply my general constructure with more arguments
  //: i {42}   // Initializing to 42
  //, s {"CppCon"} // Initializing to "CppCon"
  //, pi {}  // Initializing to nullptr
  {
  }

  Widget5(int x)
  : i { x }   // Initializing to x
  , s {"CppCon"} // Initializing to "CppCon"
  , pi {}  // Initializing to nullptr


  {}

  int i;
  std::string s;
  int* pi;
};



//
struct Widget6
{
  int i {42}; // Initializing to 42
  std::string s {"CppCon"}; // Initializing to "CppCon"
  int* pi {}; // Initializing to nullptr
};
