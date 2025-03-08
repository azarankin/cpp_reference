#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

void Foo(std::shared_ptr<std::vector<int>> pv)
{
	std::ranges::reverse(*pv);
}


class Person1: std::enable_shared_from_this<Person1>
{
	std::shared_ptr<std::string>  _name{};


public:
	explicit Person1(std::string name) : _name{ std::make_shared<std::string>(name)} {}
	const std::shared_ptr<std::string> get_name() const
	{
		return _name;
	}
	const std::shared_ptr<Person1> get_me() 
	{
		//return std::make_shared<Person1>(*this); //its creating another object
		return shared_from_this(); //shared_from_this<Person1>()
	}
};

void Foo1()
{
	std::shared_ptr<std::string> s;
	{
		Person1 p("arthur");
		s = p.get_name();
	}

	std::ranges::reverse(*s);
	// s will be still available


	auto p = std::make_shared<Person1>("arthur");
	auto q = p->get_name();
}





class Person		//based on https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/

{
	std::string m_name;
	std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr

public:

	Person(const std::string& name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}

	std::shared_ptr<Person> getPartner() const { return m_partner.lock(); } // use lock() to convert weak_ptr to shared_ptr
	const std::string& getName() const { return m_name; }
};


int main()
{
	auto sp{ std::make_shared<std::vector<int>>(std::initializer_list<int>{1, 2, 3}) };
	Foo(sp);	//shared pointer increase it counter by coping
	// not destroyed from the scope
	//also make a weak ptr for less conflict with shared, for objects



	Foo1();


	// Shared ptr structure
	// Object_ptr => [Control block: Strong prt count (1) & Weak ptr count (0)] => The Object



	auto lucy{ std::make_shared<Person>("Lucy") };
	auto ricky{ std::make_shared<Person>("Ricky") };

	partnerUp(lucy, ricky);

	auto partner = ricky->getPartner(); // get shared_ptr to Ricky's partner
	std::cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';


	return 0;
}


