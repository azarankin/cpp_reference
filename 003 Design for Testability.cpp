/***
 * Design for Testability
 * Separate concerns 
 * Move the member into a private namespace or into another class (as a separate service).
 */
#include <memory>
#define private public

template <typename Type, size_t Capacity> //Capacity right name for size
class FixedVectorTemp
{
public:
 // ...

private:
 // ...

 void destroy( Type* first, Type* last ) //how to test a private function?
 {
  for ( ; first != last; ++first ) {
 first->~Type();
  }
 }

 size_t size_;
 std::byte raw_[Capacity * sizeof(Type)];
};


// This is the design favored by the C++ standard library:

template<
 class T,
 class Allocator = std::allocator<T>
> class vector;

template< class ForwardIt >
constexpr void destroy( ForwardIt first, ForwardIt last );









#include <memory>
#include <vector>
#include <cstddef>
#include <type_traits>



// FixedVector class definition
class FixedVectorTest;

template <typename Type, size_t Capacity, typename Allocator = std::allocator<Type>>
class FixedVector {
public:
 using allocator_type = Allocator;
 using value_type = Type;

 FixedVector() : storage_(Capacity) {}

 void push_back(const Type& value) 
 {
  storage_.push_back(value);
 }

namespace FixedVectorUtilsa 
{
  template <typename ForwardIt>
  void destroy(ForwardIt first, ForwardIt last) 
  {
   for (; first != last; ++first) first->~ValueType();
  }
}

private:
 
// void destroy() 
// {
//  FixedVectorUtils::destroy(/* parameters */);
// }
 
//friend class FixedVectorTest;
};

// Example usage
int main() {
//  FixedVectorTemp<int, 10> vec;
//  vec.push_back(1);
//  vec.push_back(2);
//  vec.push_back(3);


 return 0;
}