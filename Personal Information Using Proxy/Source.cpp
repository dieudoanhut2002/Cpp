#include <iostream>
#include <string>

//Triển khai giao diện Interface chung cho Proxy và ProxyObject
class Person {
public:
    virtual ~Person() {};    // Phải khởi tạo hàm pure Virtual Destructor ở Interface thì mới gọi được Destructor ở các Child Classes
    virtual void operation() = 0;
};

// Class RealObject quản lý dữ liệu thật 

class FootballPlayer {
public:
    std::string name;
    int age;
    std::string sex;
    FootballPlayer(std::string att1, int att2, std::string att3, std::string att4, int att5) : name(att1), age(att2), sex(att3), wife(att4), income(att5) {}
private:
    std::string wife;
    int income;    
};

// Triển khai Proxy Object Class chỉ cho truy cập đến 2 thuộc tính của Real Object

class ProxyObject : public Person {
public:
    std::string name_;
    int age_;
    ProxyObject(const FootballPlayer& fb) : name_(fb.name), age_(fb.age) {};
    void operation() {
        std::cout << "Football Player Information:\n Player's name: " << this->name_ << "\n Age: " << this->age_ << std::endl; 
        // Các thao tác trên Proxy Object không làm ảnh hưởng RealObject, qua đó bảo vệ và ẩn đi dữ liệu thật của RealObject
    }
};
class ProxySevices : public Person {
private:
    FootballPlayer rlobj__;
    ProxyObject* pobj;
public:
    ProxySevices(const FootballPlayer& obj) : rlobj__(obj), pobj(nullptr) {};
    ~ProxySevices() {
        if (pobj) {
            delete pobj;
            pobj = nullptr;
            std::cout << "Destructor!\n";
        }
    }
    void operation() {
        if (!pobj) {
            pobj = new ProxyObject(rlobj__);
            std::cout << "New Proxy is created!\n";
        }
        else std::cout << "Proxy was created before!\n";
        pobj->operation();
    }
};

int main() {
    FootballPlayer ronaldo("Ronaldo", 38, "male", "Lora", 10000);
    Person* people = new ProxySevices(ronaldo);
    people->operation();
    people->operation();
    people->operation();

    delete people;
    return 0;
}
