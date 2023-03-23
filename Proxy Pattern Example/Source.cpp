/*

#include <iostream>
#include <string>

// Image interface
class Image {
public:
    virtual void display() = 0;
};

// Real Image class that loads and displays images
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        load(filename);
    }

    void display() override {
        std::cout << "Displaying image " << filename << std::endl;
    }

    void load(const std::string& filename) {
        std::cout << "Loading image " << filename << std::endl;
        // Load image from file system
    }
};

// Proxy class that creates RealImage objects on demand
class ImageProxy : public Image {
private:
    RealImage* realImage = nullptr;
    std::string filename;
    bool authorized;

public:
    ImageProxy(const std::string& filename, bool authorized) : filename(filename), authorized(authorized) {}

    void display() override {
        if (!authorized) {
            std::cout << "Access denied to image " << filename << std::endl;
            return;
        }
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    // Create an authorized ImageProxy object
    Image* image1 = new ImageProxy("sensitive_image.jpg", true);
    image1->display();

    // Create an unauthorized ImageProxy object
    Image* image2 = new ImageProxy("sensitive_image.jpg", false);
    image2->display();

    // Create a RealImage object directly
    Image* image3 = new RealImage("normal_image.jpg");
    image3->display();

    return 0;
}

*/


/*

#include <iostream>
#include <string>
class Subject {
public:
    virtual void request() = 0;
};
class RealSubject : public Subject {
public:
    void request() {
        // Implementation of request
    }
};
class Proxy : public Subject {
private:
    RealSubject realSubject;
    bool checkAccess() {
        // Check access permission
        return true;
    }
public:
    void request() {
        // Perform additional functionality before calling request() on RealSubject
        if (checkAccess()) {
            realSubject.request();
            // Perform additional functionality after calling request() on RealSubject
        }
    }
};


int main() {
    Proxy proxy;
    proxy.request();

    return 0;
}


*/


/*

#include <iostream>
#include <memory>
class IAccount {
public:
    virtual void deposit(int amount) = 0;
    virtual void withdraw(int amount) = 0;
    virtual int get_balance() const = 0;
};
class Account : public IAccount {
private:
    int balance_;
public:
    Account(int balance) : balance_(balance) {}

    void deposit(int amount) override {
        balance_ += amount;
    }

    void withdraw(int amount) override {
        if (balance_ >= amount) {
            balance_ -= amount;
        }
        else {
            std::cout << "Not enough balance!" << std::endl;
        }
    }

    int get_balance() const override {
        return balance_;
    }

};

class AccountProxy : public IAccount {
private:
    std::unique_ptr<Account> account_;
public:
    AccountProxy(int balance) : account_(new Account(balance)) {}

    void deposit(int amount) override {
        account_->deposit(amount);
    }

    void withdraw(int amount) override {
        account_->withdraw(amount);
    }

    int get_balance() const override {
        return account_->get_balance();
    }
};
class Account : public IAccount {
private:
    int balance_;
public:
    Account(int balance) : balance_(balance) {}

    void deposit(int amount) override {
        balance_ += amount;
    }

    void withdraw(int amount) override {
        if (balance_ >= amount) {
            balance_ -= amount;
        }
        else {
            std::cout << "Not enough balance!" << std::endl;
        }
    }

    int get_balance() const override {
        return balance_;
    }


};

class AccountProxy : public IAccount {
public:
    AccountProxy(int balance) : account_(new Account(balance)) {}

    void deposit(int amount) override {
        account_->deposit(amount);
    }

    void withdraw(int amount) override {
        account_->withdraw(amount);
    }

    int get_balance() const override {
        return account_->get_balance();
    }

private:
    std::unique_ptr<Account> account_;
};


*/


#include<iostream>

class IService {
public:
    virtual void operation() = 0;
};
class realService : public IService {
    private:
        
        int attribue1;
    public:
        realService(int att1) : attribue1(att1) {};
        void operation() override {
            // do some additional actions.
            std::cout << " You have entered Service zone, do what you want here!";
        }
};
class proxyService : public IService {
    private:
        const std::string authCode = "12345";
        std::unique_ptr<realService> s;
        std::string chk;
    public:
        void operation() override {
            if (checkAccess(chk))
            {
                s->operation();
            }
            else {
                std::cout << " You entered invalid an authorized code!";
            }
        }
        bool checkAccess(std::string check) {
            std::cout << "Please enter the authorize code:\n";
            std::cin >> check;
            return (check == authCode);
        }
};

int main()
{
    proxyService p;
    std::string check_;
    p.checkAccess(check_);
    p.operation();
    return 0;
}
