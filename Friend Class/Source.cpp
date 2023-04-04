#include <iostream>

class Rectangle {
private:
	int width;
	int height;
	int RectangleArea() {
		return width * height / 2;	// Để giá trị nhỏ = 1/2 đế dễ phân biệt với 
	}								// hàm tính diện tích trực tiếp trong Class Square
protected:
	int RectanglePerimeter() {
		return (width + height) * 2;
	}
public:
	Rectangle(int w, int h) : width(w), height(h) {};
	
	friend class Square;
};
class Square: public Rectangle {
private:
	int side;
public:
	Square(int x) : Rectangle(x, x), side(x) {};
	int SquareArea() {
		return side * side;
	}
	int RectangleArea() {
		return Rectangle::RectangleArea();
	}
	int Perimeter() {
		return Rectangle::RectanglePerimeter();
	}
};
int main() {
	Square sq(5);
	std::cout << sq.SquareArea() << std::endl;
	std::cout << sq.RectangleArea() << std::endl;
	std::cout << sq.Perimeter();
	return 0;
}