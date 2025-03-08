#include <iostream>

// Helper constexpr function to check if a number is divisible by any number in the range [2, n-1]
constexpr bool is_prime(int n, int divisor = 2) {
    if (n <= 2) return (n == 2); // 2 is prime, and numbers <= 1 are not prime
    if (n % divisor == 0) return false; // Divisible by divisor, not prime
    if (divisor * divisor > n) return true; // No divisor found, n is prime
    return is_prime(n, divisor + 1); // Check next divisor
}

// Constexpr function to print all prime numbers up to a certain limit
constexpr void print_prime_numbers(int limit) {
    for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            std::cout << i << ", ";
        }
    }
}

int main() {
    constexpr int LAST = 97; // Set the limit for prime checking
    std::cout << "Prime Numbers: ";
    print_prime_numbers(LAST);
    std::cout << std::endl;
    return 0;
}
