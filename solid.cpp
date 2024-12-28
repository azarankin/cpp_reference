/*
* Single Responsibility Principle: Each class is responsible for implementing only one algorithm or functionality.
* Open/Closed Principle: A class and its methods should be open for extension but closed for modification.
* Liskov Substitution Principle: Replacing a parent object with a child object should not affect the program's behavior.
* Interface Segregation Principle: A class should not implement interfaces it does not need.
* Dependency Inversion Principle: High-level modules should not depend on low-level modules but rather on abstractions.

* עקרון האחריות היחידה (Single Responsibility Principle): כל מחלקה אחראית ליישום פונקציה או אלגוריתם אחד בלבד.
*
*
*
*לא
class Report {
*public:
*    void generateReport() {
*        // Logic for generating the report
*    }
*
*    void saveReportToFile(const std::string& filename) {
*        // Logic for saving the report to a file
*    }
*
*    void printReport() {
*        // Logic for printing the report
*    }
*};
*
*
*
*
*
*
class ReportGenerator {
public:
    std::string generateReport() {
        // Logic for generating the report
        return "Report Content";
    }
};

class ReportSaver {
public:
    void saveReportToFile(const std::string& report, const std::string& filename) {
        // Logic for saving the report to a file
    }
};

class ReportPrinter {
public:
    void printReport(const std::string& report) {
        // Logic for printing the report
    }












* עקרון פתוח/סגור (Open/Closed Principle): מחלקה ומתודות שלה צריכות להיות פתוחות להרחבה אך סגורות לשינויים.
*
*
*לא
*
*class Employee {
*public:
*    virtual double calculateSalary() const = 0;
*    virtual ~Employee() = default;
*};
*
*class FullTimeEmployee : public Employee {
*public:
*    double calculateSalary() const override {
*        return 5000;
*    }
*};
*
*class PartTimeEmployee : public Employee {
*public:
*    double calculateSalary() const override {
*        return 2000;
*    }
*};
*
*class SalaryCalculator {
*public:
*    double calculate(const Employee& employee) {
*        return employee.calculateSalary();
*    }
*};
*
*
*
*
*
class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
public:
    double calculateSalary() const override {
        return 5000;
    }
};

class PartTimeEmployee : public Employee {
public:
    double calculateSalary() const override {
        return 2000;
    }
};

class SalaryCalculator {
public:
    double calculate(const Employee& employee) {
        return employee.calculateSalary();
    }
};


* עקרון החלפת ליסקוב (Liskov Substitution Principle): החלפת אובייקט אב באובייקט בן לא תפגע בהתנהגות התוכנית.
*
*
*
* לא
* class Rectangle {
*protected:
*    int width;
*    int height;
*public:
*    void setWidth(int w) { width = w; }
*    void setHeight(int h) { height = h; }
*    int getWidth() const { return width; }
*    int getHeight() const { return height; }
*    int area() const { return width * height; }
*};
*
*class Square : public Rectangle {
*public:
*    void setWidth(int w) override {
*        width = w;
*        height = w; // שובר את החוזה של Rectangle
*    }
*    void setHeight(int h) override {
*        height = h;
*        width = h; // שובר את החוזה של Rectangle
*    }
*};
*
*
*

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
protected:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const override { return width * height; }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int s) : side(s) {}
    int area() const override { return side * side; }
};









* עקרון הפרדת ממשקים (Interface Segregation Principle): מחלקה לא תממש ממשקים שהיא אינה זקוקה להם.
*
*
*
*
* לא
* class Worker {
*public:
*    virtual void work() = 0;
*    virtual void eat() = 0;
*};
* 
*class HumanWorker : public Worker {
*public:
*    void work() override {
*        // Work logic for a human
*    }
*    void eat() override {
*        // Eating logic for a human
*    }
*};
* 
*class RobotWorker : public Worker {
*public:
*    void work() override {
*        // Work logic for a robot
*    }
*    void eat() override {
*        // What should a robot do here? Robots don't eat!
*    }
*};
*
*
*
*
*
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class HumanWorker : public Workable, public Eatable {
public:
    void work() override {
        // Work logic for a human
    }

    void eat() override {
        // Eating logic for a human
    }
};

class RobotWorker : public Workable {
public:
    void work() override {
        // Work logic for a robot
    }
};

















* עקרון היפוך תלות (Dependency Inversion Principle): מודולים ברמה גבוהה לא יהיו תלויים במודולים ברמה נמוכה, אלא באבסטרקציות.
*
*
*
*
*
*
*לא
*class FileLogger {
*public:
*    void log(const std::string& message) {
*        // Logic to log message to a file
*    }
*};
*
*class Application {
*    FileLogger logger; // תלות ישירה במימוש ספציפי
*public:
*    void process() {
*        // Logic
*        logger.log("Processing started...");
*    }
*};
*
*

class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

class FileLogger : public ILogger {
public:
    void log(const std::string& message) override {
        // Logic to log message to a file
    }
};

class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        // Logic to log message to the console
    }
};

class Application {
    ILogger& logger; // תלות באבסטרקציה, לא במימוש ספציפי
public:
    Application(ILogger& logger) : logger(logger) {}

    void process() {
        // Logic
        logger.log("Processing started...");
    }
};

 **/