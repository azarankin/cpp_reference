#include <string>
/*
class Person
{
    std::string name_{};
    int age_{};
    std::string name_temp{};
    int age_temp{};

public:
    explicit Person() = default;

    Person& age(int age)
    {
        age_temp = age;
        return *this;
    }

    Person& name(const std::string& name)
    {
        name_temp = name;
        return *this;
    }


    Person& builder()
    {
        name_ = name_temp;
        age_ = age_temp;
        return *this;
    }



};



//@CLK
int main1()
{
    Person* p = new Person;
    p->age(20).name("Arthur").builder();

}
*/




#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr
#include <execution>
class Person
{
    std::string name_;
    int age_;

    // Private constructor to restrict direct instantiation
    explicit Person(const std::string& name, int age) : name_(name), age_(age) {}

public:
    // Nested Builder class
    class Builder
    {
        std::string name_temp{};
        int age_temp{0};

    public:
        Builder& age(int age)
        {
            age_temp = age;
            return *this;
        }

        Builder& name(const std::string& name)
        {
            name_temp = name;
            return *this;
        }

        std::unique_ptr<Person> unique_ptr()
        {
            if (name_temp.empty() || age_temp == 0) throw std::exception("values not set correctly");
            return std::make_unique<Person>(name_temp, age_temp);
        }

        Person build() const
        {
            return Person(name_temp, age_temp);
        }
    };

    // Display method for testing
    void display() const
    {
        std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
    }
};

// Main function demonstrating the Builder Pattern
int main()
{
    // Use the Builder to create a Person object
    auto p = Person::Builder().age(20).name("Arthur").unique_ptr();
    p->display(); // Output: Name: Arthur, Age: 20

    return 0;
} 
