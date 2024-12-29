#include <memory>
#include <iostream>

class singleton
{
    //inline static singleton* instance {nullptr};
    inline static std::unique_ptr<singleton> instance;
    explicit singleton() {}

public:


    singleton(const singleton&) = delete;
    singleton& operator=(const singleton&) = delete;

    static singleton* getInstance() {
        //if (instance == nullptr)
        if (!instance)
        {
            //instance = new singleton();
            instance.reset(new singleton);
            //instance = std::make_unique<singleton>();
        }
        //return instance;
        return instance.get();
    }


};

int main()
{

    singleton* a = singleton::getInstance();
    singleton* b = singleton::getInstance();

    if (a == b) { std::cout << "its a singleton"; }

}
