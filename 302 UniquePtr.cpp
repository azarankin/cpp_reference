

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

//example to make movable and not copyable resource
std::unique_ptr<std::vector<int>> Foo(std::unique_ptr<std::vector<int>> pv)
{
	std::ranges::reverse(*pv);
	return pv; //keep the unique pinter
}



int main()
{
	auto up{std::make_unique<std::vector<int>>(std::initializer_list<int>{1, 2, 3})};
	//made by "new "  "make_unique"
	up = Foo(std::move(up));	//unique pointer returned back to action

	//unique ptr transfer the pointer and avoid sharing
	//also applied in dependency injection
	

	return 0;
}





template <typename T>
class UniquePtr {
private:
    T* ptr;

public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~UniquePtr()
    {
        delete ptr;
    }


    T& operator*() const
    {
        return *ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    T* get() const
    {
        return ptr;
    }
};
