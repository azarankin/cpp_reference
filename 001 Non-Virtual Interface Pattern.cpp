/***
 * Non-Virtual Interface Pattern
 * When applying the method VirtualMethod because it instance of Derive that is inherited from Base, the actual method that is implemented is from the Derive class
 * Shown the printed results inside the Main function comments
 * 
 * Actual example in Template Method Pattern
 */

#include <iostream>
class Base
{
public:
 void RegularMethod()
 {
 std::cout << "Implementation of a Virtual Method from a Regular Method - Base\n";
 VirtualMethod();
 }
private:
 virtual void VirtualMethod() { std::cout << "Virtual Method - Base\n"; }
public:
 virtual ~Base() = default;
};

class Derive : public Base
{
private:
 void VirtualMethod() override { std::cout << "Virtua Method Override - Derive\n"; }
};

int main()
{
 Base* basic = new Derive();
 basic->RegularMethod(); // Implementation of a Virtual Method from a Regular Method - Base
 // Virtua Method Override - Derive
 delete basic;
}