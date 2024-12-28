#include <iostream>
#include <memory>
using std::cout;
using std::string;


//      IGameObject
//  Plane^       ^Boat

class IGameObject
{
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane() { cout << "Plane is created\n"; }
    //~Plane() { cout << "Plane is ended\n"; }
    void Update() {};
    void Render() {};
};


class Boat : public IGameObject
{
public:
    Boat() { cout << "Boat is created\n"; }
    //~Boat() { cout << "Boat is ended\n"; }
    void Update() {};
    void Render() {};
};
namespace Factory
{
    enum ObjectType { Plane, Boat };
    std::shared_ptr<IGameObject> /*IGameObject* */ MakeGameObjectFactory(ObjectType type)
    {
        if (type == ObjectType::Plane) return /*new*/ std::make_shared<::Plane>();
        else if (type == ObjectType::Boat)  return /*new*/ std::make_shared <::Boat>();
        else return nullptr;
    }
}







int main2()
{
    cout << "Factory Method Pattern\n";

    auto myObject{
        Factory::MakeGameObjectFactory(Factory::Plane)  // std::make_unique<IGameObject>
    };
    auto myObject2{
        Factory::MakeGameObjectFactory(Factory::Boat)
    };
    //Boat b;
    //Plane p;


    //delete myObject;
    //myObject = nullptr;
    //delete myObject;
    //delete myObject2;
}