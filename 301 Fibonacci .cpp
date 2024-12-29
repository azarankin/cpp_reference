int Fib(int n)
{
	if (n < 0) throw exception();
	if (n == 0 || n == 1) return n;
	int current = 1, previous = 0, temp;
	for (int i{ 2 }; i <= n + 1; ++i) {
		temp = previous;
		current = current + previous;
		previous = temp;
	}
	return current;
}

int Fib2(int n)
{
	if (n < 0) throw exception();
	if (n == 0 || n == 1) return n;
	int current = 0, next = 1;
	for (int i{ 2 }; i <= n + 1; ++i) {
		const int temp = current + next;
		current = next;
		next = temp;
	}
	//current = next;
	//return next;
	return next;
}

int Fib3(int n) {
	if (n < 0) throw std::exception();
	if (n == 0 || n == 1) return n;
	return Fib3(n - 1) + Fib3(n - 2);
}



template<int N>
struct Fibonacci
{
	static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0>
{
	static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
	static constexpr int value = 1;
};



/*
 * regular complexity O(2^n) {tree}
 * space O(n)
 *
 *
 *
 * with memo
 *	O(n)
 *	space O(n)
 */




#include <iostream>
#include <vector>
#include <stdexcept>

// Recursive Fibonacci function with memoization
int FibMemo(int n, std::vector<int>& memo) {
	if (n < 0) throw std::invalid_argument("Negative numbers are not allowed");

	// Base cases
	if (n == 0) return 0;
	if (n == 1) return 1;

	// Check if already computed
	if (memo[n] != -1) return memo[n];

	// Compute and store the result in memo
	memo[n] = FibMemo(n - 1, memo) + FibMemo(n - 2, memo);
	return memo[n];
}

int Fib4(int n) {
	// Create a memoization array initialized to -1
	std::vector<int> memo(n + 1, -1);
	return FibMemo(n, memo);
}


