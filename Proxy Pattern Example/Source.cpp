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

int main() {
    AccountProxy account(100);
    account.deposit(50);
    std::cout << "Balance: " << account.get_balance() << std::endl;
    account.withdraw(80);
    std::cout << "Balance: " << account.get_balance() << std::endl;
    account.withdraw(100);
    std::cout << "Balance: " << account.get_balance() << std::endl;
    return 0;
}


*/




#include<iostream>

class ServiceInterface {
public:
    virtual void operation() = 0;
};
class realService : public ServiceInterface {
    private:
        static int enterCount;
    public:
        realService(){};
        
        void operation() override {
            // do some additional actions.
            enterCount++;
            std::cout << " You have entered Service zone by " << enterCount << " time, do what you want here!\n";
        }
};
int realService::enterCount = 0;
class proxyService : public ServiceInterface {
    private:        
        realService* s;
        bool accessKey;        
    public:
        
        proxyService(bool acc) : accessKey(acc){};
        void operation() override {
            if (!checkAccess())
            {
                std::cout << "You are not allowed to enter!";
                return;
            }
            if(!s) {
                s = new realService();
                std::cout << "You have created an realService Object\n";
            }
            s->operation();
        }
        bool checkAccess() {
            // Do something on checking
            return(accessKey);
        };
};

int main()
{
    proxyService p1(true);
    p1.operation();
    p1.operation();
    p1.operation();
    proxyService p2(false);
    p2.operation();
    
    return 0;
}



/*

#include <iostream>
#include <string>


// Forward declaration of the Image class
class Image;

// Interface for the ImageProxy class
class ImageProxy
{
public:
    ImageProxy(const std::string& filename);
    ~ImageProxy();

    void display();

private:
    std::string m_filename;
    Image* m_image;
};

// Implementation of the ImageProxy class
ImageProxy::ImageProxy(const std::string& filename)
    : m_filename(filename), m_image(nullptr)
{
}

ImageProxy::~ImageProxy()
{
    delete m_image;
}

void ImageProxy::display()
{
    if (!m_image)
    {
        m_image = new Image(m_filename);
    }

    m_image->display();
}

// Implementation of the Image class
class Image
{
public:
    Image(const std::string& filename)
        : m_filename(filename)
    {
        // Load image from file
    }

    ~Image()
    {
        // Unload image from memory
    }

    void display()
    {
        // Display image on screen
    }

private:
    std::string m_filename;
};

// Usage of the ImageProxy and Image classes
int main()
{
    ImageProxy* imageProxy = new ImageProxy("image.jpg");

    // Image is not loaded yet
    imageProxy->display();

    // Image is loaded from file and displayed on screen
    imageProxy->display();

    delete imageProxy;

    return 0;
}

*/