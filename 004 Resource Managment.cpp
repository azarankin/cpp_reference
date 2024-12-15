/***
 * Resource Managment
 */

#include<string>


class Widget
{
public:
    // ...
 Widget(); // Default constructor
 Widget(Widget const& other); // Copy constructor
 Widget& operator=(Widget const& other); // Copy assignment operator
 Widget(Widget&& other) noexcept; // Move constructor
 Widget& operator=(Widget&& other) noexcept; // Move assignment operator
 ~Widget(); // Destructor
    // ...

private:
    int i;  // - i as a representative of a fundamental type
    std::string s;  // - s as a representative of a class (user-defined) type
};


class Widget_Role_of_0 //no basic operations
{
public:
//..


private:
 int i;  // - i as a representative of a fundamental type
 std::string s;  // - s as a representative of a class (user-defined) type
};


// for class is own a pointer, add a distructure

// unique ptr cant be copied // without copy operations
// have to set manualy the move operations (it always Rule of 0 or Rule of 5)
// Widget(Widget const& other) = delete; // Copy constructor
// Widget& operator=(Widget const& other) = delete; // Copy assignment operator
// Widget(Widget&& other) noexcept = default;
// Widget& operator=(Widget&& other) noexcept = default;

// shared ptr no method required