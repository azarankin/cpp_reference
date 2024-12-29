

#include <string_view>

std::string reverseString(const std::string& str) {
    std::string reversed;
    reversed.reserve(str.size()); // Reserve space to avoid reallocations

    // Traverse the string from the end to the beginning
    for (std::size_t i = str.size(); i > 0; --i) {
        reversed.push_back(str[i - 1]); // Add each character in reverse order
    }

    return reversed;
}


void reverseStringInPlace(std::string& str)
{

    size_t left = 0;
    size_t right = str.size() - 1;

    // Swap characters from the beginning and end
    while (left < right) {
        std::swap(str[left], str[right]);
        ++left;
        --right;
    }
}
