#include <iostream>

class Rectangle {
private:
	int width;
	int height;
	
protected:
	int RectanglePerimeter() {
		return (width + height) * 2;
	}
public:
	Rectangle(int w, int h) : width(w), height(h) {};
	int RectangleArea() {
		return width * height / 2;	// Để giá trị nhỏ = 1/2 đế dễ phân biệt với 
	}								// hàm tính diện tích trực tiếp trong Class Square
	friend class Square;
	friend class Test;
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
class Test {
public:
	void setWidth(Rectangle& x, int w) {        //truy cập thuộc tính Private
		x.width = w;
	}
	int RectanglePerimeter(Rectangle& x) {      // truy cập thuộc tính protected
		return (x.width + x.height) * 2;
	}
	int Perimeter(Rectangle& x) {				// truy cập thuộc tính public
		return x.RectanglePerimeter();
	}
};
int main() {
	Square sq(5);
	std::cout << sq.SquareArea() << std::endl;
	std::cout << sq.RectangleArea() << std::endl;
	std::cout << sq.Perimeter() << std::endl;
	Rectangle rec(3, 4);
	Test friendclass;
	friendclass.setWidth(rec, 5);
	std::cout << friendclass.RectanglePerimeter(rec) << std::endl;
	std::cout << friendclass.Perimeter(rec) << std::endl;
	
	return 0;
}