/*** 
 * Strategy Pattern with std::function
 * base https://www.youtube.com/watch?v=motLOioLJfg
... separation of concerns (Singel Responsible Pronciple);
 ***/
#include <memory>
#include <vector>
#include <functional>

// Base class Shape
class Shape {
public:
 Shape() = default;
 virtual ~Shape() = default;

 virtual void draw() const = 0;
 virtual void serialize() const = 0;
};


class Circle;

using DrawCircleStrategy = std::function<void(const Circle&)>;

class Circle : public Shape {
public:
 Circle(double rad, DrawCircleStrategy strategy)
  : radius{rad}, 
 // ... Remaining data members
 drawing{std::move(strategy)} 
 {}

 double getRadius() const noexcept;
 // ... getCenter(), getRotation(), ...

 void draw(/*...*/) const override {
  drawing(*this/*, ...*/);
 }

 void serialize(/*...*/) const override{};

private:
 double radius;
 // ... Remaining data members
 DrawCircleStrategy drawing;
};






class Square;

using DrawSquareStrategy = std::function<void(const Square&)>;

class Square : public Shape {
public:
 Square(double s, DrawSquareStrategy strategy)
  : side{s}, 
 // ... Remaining data members
 drawing{std::move(strategy)} 
 {}

 double getSide() const noexcept;
 // ... getCenter(), getRotation(), ...

 void draw(/*...*/) const override {
  drawing(*this/*, ...*/);
 }

 void serialize(/*...*/) const override {};

private:
 double side;
 // ... Remaining data members
 DrawSquareStrategy drawing;
};



void drawOpenGLCircleStrategy(Circle const& circle)
{

};


void drawOpenGLSquareStrategy(Circle const& circle) 
{

};



// Function to draw all shapes
void drawAllShapes(const std::vector<std::unique_ptr<Shape>>& shapes) {
 for (const auto& shape : shapes) {
  shape->draw(); // Call the draw method of each shape
 }
}

int main()
{
 using Shapes = std::vector<std::unique_ptr<Shape>>;
 
 // Creating some shapes
 Shapes shapes;
 shapes.emplace_back( std::make_unique<Circle>(2.0, drawOpenGLCircleStrategy) );
 shapes.emplace_back( std::make_unique<Square>(1.5, drawOpenGLSquareStrategy) );
 shapes.emplace_back( std::make_unique<Circle>(4.2, drawOpenGLCircleStrategy) );

 // Drawing all shapes
 drawAllShapes(shapes);
}

