#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>




//RValue
std::vector<int> ReverseVector(std::vector<int>& v)
{
	std::ranges::reverse(v); //std::reverse(std::begin(v), std::end(v));
	return v;
}

//LValue
std::vector<int> ReverseVector(std::vector<int>&& v)
{
	std::ranges::reverse(v); //std::reverse(std::begin(v), std::end(v));
	return std::move(v); //return v; // RValue
}

//std::forward
template<typename T>
std::vector<int> DoReverse(T&& urv)
{
	return /*static_cast<std::vector<int>>(*/ReverseVector(std::forward<T>(urv))/*)*/;
}



#define Time std::chrono::high_resolution_clock
#define Duration(calc) std::chrono::duration_cast<std::chrono::nanoseconds>(calc)

int main(int argc, char* argv[])
{
	std::cout << "std move \n";
	auto start{ Time::now()};
	auto end{ Time::now() };

	std::vector<int> v1{ 1,2,3 };
	std::vector<int> v2_temp{ 1,2,3 };
	//LValue ref
	start = Time::now();
	{
		//std::vector<int> v1 = ReverseVector(v);
		v1 = ReverseVector(v1);
		std::vector<int> v2 = DoReverse(v2_temp);	//&
	}
	end = Time::now();
	auto v1_2_duration_ns = Duration(end - start);


	//RValue move
	std::vector<int> v4_temp{ 1,2,3 };	//v4_temp
	start = Time::now();
	{
		std::vector<int> v3 = ReverseVector({1, 2, 3});
		//std::vector<int> v4 = DoReverse(std::move(v_temp	// v4_temp should be empty after that
		std::vector<int> v4 = DoReverse(std::move(v4_temp));	//&
	}
	end = Time::now();
	auto v3_4_duration_ns = Duration(end - start);


	std::cout << "Durations (Do it in Release mode)\n";
	std::cout << "LValue: " << v1_2_duration_ns.count() << "ns\n";		//300ns
	std::cout << "RValue: " << v3_4_duration_ns.count() << "ns\n";	//100ns


	std::cout << "\n\n";


	std::cout << "v1 values ";
	for(auto& i: v1) 
		std::cout << i << " ";	// 3 2 1
	std::cout << "\n";

	std::cout << "v2_temp (ref) values ";
	for (auto& i : v2_temp)
		std::cout << i << " ";	//
	std::cout << "\n";


	std::cout << "v4_temp (std::move) values ";
	for (auto& i : v4_temp)
		std::cout << i << " ";	//
	std::cout << "\n";


    return 0;	//time should measure on release
}
