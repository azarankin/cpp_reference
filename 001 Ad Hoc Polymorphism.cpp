/***
 * Ad Hoc Polymorphism
 * Adhoc describes how the methods of one class will act after their inheritance to another class.
 * Most known 5 types of methods that base on the Ad-hoc definition
 virtual void AbstractMethod();
 void RegularMethod() { }
 void NewMethod() { }
 virtual void VirtualMethod() { }
 void OverridedMethod override () { }
 */


#include <iostream>

class Base
{
public:
 virtual void AbstructMethod() = 0; // no implementation
 void RegularMethod() { std::cout << "Regular Method - Base\n"; }
 virtual void VirtualMethod() { std::cout << "Virtual Method - Base\n"; }
public:
 virtual ~Base() = default;
};

class Derive : public Base
{
public:
 void AbstructMethod() { std::cout << "Abstruct Method implementation - Derive\n"; }
 void RegularMethod() { std::cout << "New implementation - Regular Method - Derive\n"; }
 void VirtualMethod() override { std::cout << "Virtua Method Override - Derive\n"; }
};

int main()
{
 Base* basic = new Derive();
 basic->AbstructMethod(); // Abstruct Method implementation - Derive
 basic->RegularMethod(); // Regular Method - Base
 basic->VirtualMethod(); // Virtua Method Override - Derive
 delete basic;
}
