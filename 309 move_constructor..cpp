#include <iostream>
#include <vector>

class Resource
{
    std::vector<int> _v{};
    int* ptr{};
public:

    Resource() : ptr(new int(0)) {}

    Resource(const Resource& o) : _v{ o._v }, ptr{ new int(*o.ptr) }
    {
        // Deep copy of the pointer
    }

    Resource(Resource&& o) noexcept : _v{ std::move(o._v) }, ptr{ o.ptr }
    {
        o.ptr = nullptr; // Ensure the source object doesn't delete the moved resource
    }

    Resource& operator=(const Resource& o)
    {
        if (&o == this)
            return *this;

        _v = o._v;

        if (ptr)
            delete ptr;

        ptr = new int(*o.ptr); // Deep copy

        return *this;
    }

    Resource& operator=(Resource&& o) noexcept
    {
        if (&o == this)
            return *this;

        _v = std::move(o._v);

        delete ptr; // Release current resource
        ptr = o.ptr; // Transfer ownership
        o.ptr = nullptr; // Nullify the source object

        return *this;
    }

    ~Resource()
    {
        delete ptr;
    }
};



// based on https://www.learncpp.com/cpp-tutorial/move-constructors-and-move-assignment/
template<typename T>
class Auto_ptr
{
	T* m_ptr{};
public:
	Auto_ptr(T* ptr = nullptr)
		: m_ptr{ ptr }
	{
	}

	~Auto_ptr()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr(const Auto_ptr& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr(Auto_ptr&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr& operator=(const Auto_ptr& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr& operator=(Auto_ptr&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};


Auto_ptr<Resource> generateResource()
{
    Auto_ptr<Resource> res{ new Resource };
    return res;
}

int main()
{
    std::cout << "move constructor\n";
    Resource m;
    Resource m2(std::move(m)); // Moving m to m2

    Auto_ptr<Resource> a{};
    //1- constructor
    a = generateResource();
    //2- constructor        Auto_ptr<Resource> res{ new Resource };
    //3- move operator   returned from the function	//return res;
	//4- destructor for empty Object


	//without the move operator=  Auto_ptr& operator=(Auto_ptr&& a) noexcept
	//1- constructor
	//2- constructor
	//3- copy operator,		not recommended
	//4- destructor


	std::vector<Resource> resources{ Resource(), Resource(), Resource() };

	std::vector<Resource> resources_copy(resources.capacity());
	for (auto&& r: resources)
	{
		resources_copy.push_back(std::move(r));
		//m = std::move(r); //move resource
	}


	//Add an example for "moveable and not copyable resource"


}
