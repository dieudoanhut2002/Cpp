/*
#include <iostream>

int add(const int a, const int b) {
	return a + b;
}
int substract(const int a, const int b) {
	return a - b;
}
int *calculate(int a, int b, std::string c) {	
	int add_ = add(a, b), substract_ = substract(a, b);
	if (c == "add") return &add_;
	if (c == "substract") return &substract_;
	return 0;
}
int *(*ptr)(int, int, std::string) = &calculate;   
int (*add_)(int, int) = &add;   
int (*substract_)(int, int) = &substract;   

int main() {
	int* p = calculate(3, 4, "add");
	std::cout << (*p);
	p = calculate(3, 4, "substract");
	std::cout << (*p);
	std::cout << (*add_)(3, 4);
	std::cout << (*substract_)(3, 4);
}

*/

/*
#include <iostream>

int add(const int a, const int b) {
	return a + b;
}
int substract(const int a, const int b) {
	return a - b;
}
int (*calculate(std::string c))(int, int) {
	if (c == "add") return &add;
	if (c == "substract") return &substract;
	return nullptr;
}

int main() {
	std::string op;
	int(*p)(int, int) = calculate(op);
	op = "add";
	std::cout << p(3, 4);
}

*/

#include <iostream>

int add(const int a, const int b) {
	return a + b;
}

int substract(const int a, const int b) {
	return a - b;
}

void* calculate(std::string c) {	
	if (c == "add") return (void*)&add;
	if (c == "substract") return (void*)&substract;
	return nullptr;
}

int main() {
	int (*sum)(const int a, const int b) = (int(*)(const int a, const int b)) calculate("add");
	std::cout << sum(200, 300) << std::endl; 
}


