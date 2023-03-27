#include <iostream>
#include <mutex>

class Singleton {
	private:
		static Singleton* instance;  
		static std::mutex mtx;  // declare a static object of mutex class that allow only one thread can access the Singleton at one time
		Singleton() {};// Initialize a private Contructor to prevent user can define Singleton directly
		~Singleton() {};// Initialize a private Destructor to prevent user can delete Singleton directly
		Singleton(const Singleton&) = delete;  // to delete the copy Contructor function
		Singleton& operator=(const Singleton&) = delete; // to delete the operator = overload function
		static int singletonTryCount; // to count the number of Singleton Initializing Trying 
public:
	static Singleton* getInstance() {
		std::lock_guard<std::mutex> lock(mtx);
		if (!instance)
		{
			instance = new Singleton();
			std::cout << "Initialized a new Singleton\n";
		}
		else {
			std::cout << "There was a running Singleton\n";
		}
		singletonTryCount++;
		return instance;
	}
	void doSomething() {
		std::cout << "This is Singleton Initilizing Trying Number: " << singletonTryCount << std::endl;
	}
};
int Singleton::singletonTryCount = 0;          // init value for static count variable
Singleton* Singleton::instance = nullptr;		// initialize nullptr value for a static pointer 
std::mutex Singleton::mtx;						// initialize static mtx is an object of mutex class

int main() {

	std::thread t1([]() {
		Singleton* s1 = Singleton::getInstance();
	s1->doSomething();
	Singleton* s2 = Singleton::getInstance();
	s2->doSomething();
	Singleton* s3 = Singleton::getInstance();
	s3->doSomething();
		});
	std::thread t2([]() {
		Singleton* s1 = Singleton::getInstance();
	s1->doSomething();
	Singleton* s2 = Singleton::getInstance();
	s2->doSomething();
	Singleton* s3 = Singleton::getInstance();
	s3->doSomething();
		});
	t1.join();
	t2.join();
	return 0;
}
