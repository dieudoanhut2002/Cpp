#include <iostream>
#include <string>



class Shape {
public:
    virtual void draw() = 0;
};
class Circle : public Shape {
public:
    void draw() override {
        // Triển khai để vẽ một hình tròn
        std::cout << "Circle drawn completed!\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        // Triển khai để vẽ một hình chữ nhật
        std::cout << "Rectangle drawn completed!\n";
    }
};
class ShapeFactory {
public:
    static Shape* createShape(const std::string& shapeType) {
        if (shapeType == "circle") {
            return new Circle();
        }
        else if (shapeType == "rectangle") {
            return new Rectangle();
        }
        else {
            return nullptr;
        }
    }
};
int main() {
    Shape* circle = ShapeFactory::createShape("circle");
    Shape* rectangle = ShapeFactory::createShape("rectangle");

    // Sử dụng các đối tượng tạo ra
    circle->draw();
    rectangle->draw();

    delete circle;
    delete rectangle;

    return 0;
}

