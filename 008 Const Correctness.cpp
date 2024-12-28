/***
 * Const Correctness
 * By default, make member functions const
 * Const correctness is part of the semantics of the class
 * Encapsulate thing will prevent issues letter
 * 
 */

#include <ostream>

template< typename Type, size_t Capacity >
class FixedVector final
{

public:
  // ...
  Type const* begin_tmp() const noexcept; //will not change the state of the class but it still point to mutable elements, less reccomended
  Type* begin_tmp() const noexcept;
  Type const * end_tmp() const noexcept;

  //better to use for future flexability for change
  //less display the pointer in the code, encapsulate the details
  using iterator = Type*;
  using const_iterator = const Type*;
  const_iterator begin() const noexcept;
  iterator begin() const noexcept;
  const_iterator end() const noexcept;

  // ...
};

std::ostream& operator<<( std::ostream& os, FixedVector<int, 10> v )
{
  for( int i : v ) { /*...*/ } //os << i; os << ','

  return os;
}





namespace std2
{

template< typename Type, typename Deleter = std::default_delete<Type> >
class unique_ptr
{
public:
    using pointer = Type*;

    // Constructor to initialize the pointer
    explicit unique_ptr(pointer ptr) : ptr_{ptr} {}

    // Getter for the pointer
    pointer get() const noexcept { return ptr_; }

    // Destructor to clean up the pointer
    ~unique_ptr() { /*delete*/ Deleter(ptr_); }

private:
    pointer ptr_; // Managed pointer
};

} // namespace std2

int main()
{
    // Create a unique_ptr managing a const int initialized to 5
    std2::unique_ptr<int const> const ptr1{new int/* const*/(5)};

    // Create a raw const pointer to an int initialized to 4
    int const* const ptr2 {new int(4)};

    // Output the values
    std::printf("ptr1 points to: %d\n", *ptr1.get());
    std::printf("ptr2 points to: %d\n", *ptr2);

    // Clean up raw pointer ptr2
    delete ptr2;

    return 0;
}
