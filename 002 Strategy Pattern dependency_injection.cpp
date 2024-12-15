/*** 
 * Strategy Pattern
 * base https://www.youtube.com/watch?v=motLOioLJfg
 * By means of the Strategy design pattern we have:
... extracted implementation details (Singel Responsible Pronciple);
... created the opportunity for easy change;
... created the opportunity for easy extension (Open-Close Principle);
 ***/

#include <memory>
#include <vector>

// Base class Shape
class Shape {
public:
 Shape() = default;
 virtual ~Shape() = default;

 virtual void draw() const = 0;
 virtual void serialize() const = 0;
};

// Forward declaration of Circle
class Circle;

// Strategy Interface
class DrawCircleStrategy {
public:
 virtual ~DrawCircleStrategy() = default;

 virtual void draw(const Circle& circle) const = 0; // Draw Circle by reference
};

// Circle class implementing Shape
class Circle : public Shape {
public:
 Circle(double rad, std::unique_ptr<DrawCircleStrategy> strategy)
  : radius{rad}, drawing{std::move(strategy)} 
 {}

 double getRadius() const noexcept { 
  return radius; 
 }

 void draw() const override {
  drawing->draw(*this); // Pass *this (reference) to strategy
 }

 void serialize() const override {
  // Serialization logic (to be implemented)
 }

private:
 double radius; // Circle radius
 std::unique_ptr<DrawCircleStrategy> drawing; // Strategy for drawing
};





class Square;

class DrawSquareStrategy {
public:
 virtual ~DrawSquareStrategy() = default;

 virtual void draw(const Square& square) const = 0; // Draw Circle by reference
};


class Square : public Shape {
public:
 Square(double s, 
  std::unique_ptr<DrawSquareStrategy> strategy)
  : side{s}, 
 // ... Remaining data members
 drawing{std::move(strategy)} 
 {}

 double getSide() const noexcept;
 // ... getCenter(), getRotation(), ...

 void draw(/*...*/) const override {
  drawing->draw(*this/*, ...*/);
 }

 void serialize(/*...*/) const override {};

private:
 double side;
 // ... Remaining data members
 std::unique_ptr<DrawSquareStrategy> drawing;
};



class OpenGLCircleStrategy : public DrawCircleStrategy {
public:
 virtual ~OpenGLCircleStrategy() {}

 void draw(Circle const& circle) const override{};
};

class OpenGLSquareStrategy : public DrawSquareStrategy {
public:
 virtual ~OpenGLSquareStrategy() {}

 void draw(Square const& square) const override{};
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
 shapes.emplace_back(std::make_unique<Circle>(2.0, 
 std::make_unique<OpenGLCircleStrategy>()));
 shapes.emplace_back(std::make_unique<Square>(1.5, 
 std::make_unique<OpenGLSquareStrategy>()));
 shapes.emplace_back(std::make_unique<Circle>(4.2, 
 std::make_unique<OpenGLCircleStrategy>()));

 // Drawing all shapes
 drawAllShapes(shapes);
}

