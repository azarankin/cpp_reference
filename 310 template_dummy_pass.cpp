#include <iostream>

// https://www.modernescpp.com/index.php/c-insights-variadic-templates/


//struct pass
//{
//	template<typename ...T>
//	explicit pass(T...) {}
//};


template<typename... Args>
void expend(Args&&... args)
{
	//pass{ ...(std::cout << args << ", ") };
	bool all{(... &&args)};
	(... && (std::cout << std::forward<Args>(args) << ", "));
	std::cout << '\n' << std::boolalpha << "sigma bool: " << all;
	//can use:		&&		""		,

}

int main()
{
	std::cout << std::boolalpha << "Dummy pass template:\n";
	expend(42, "answer", true, true, false, true);

}