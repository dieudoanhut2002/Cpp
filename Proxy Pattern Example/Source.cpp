/*


#include <iostream>
#include <string>
#include <thread>
//Triển khai giao diện Interface chung cho Proxy và ProxyImage
class Image {
public:
    virtual ~Image() {};    // Phải khởi tạo hàm pure Virtual Destructor ở Interface thì mới gọi được Destructor ở các Child Classes
    virtual void display() = 0;
};

// Class RealImage quản lý dữ liệu thật 

class RealImage {
public:
    std::string imageName;
    int imagePrize;
    RealImage(std::string name, int prize) : imageName(name), imagePrize(prize) {}; 
};

//Triển khai lớp ProxyImage kế thừa từ Interface, giao diện giống RealImage 
//và thực hiện copy dữ liệu từ RealImage
class ProxyImage : public Image {
public:
    std::string imageName_;
    int imagePrize_;
    ProxyImage(const RealImage& im) {
        this->imageName_ = im.imageName;
        this->imagePrize_ = im.imagePrize;
    };    
    void display() {
        // Hiển thị thông tin trong ProxyImage
        std::cout << "Image " << imageName_ << "'s prize is: " << imagePrize_ << "USD" << std::endl;
    }
};

//Triển khai lớp Proxy kế thừa từ Interface trên, bao gồm một con trỏ tới đối tượng ProxyImage
class Proxy : public Image {  
private:
    RealImage realim__;
    ProxyImage* image__;
public:
    Proxy(const RealImage& realim) : realim__(realim), image__(nullptr) {};     
    ~Proxy() {
        if (image__) {               // Nếu Proxy đã được khởi tạo
            delete image__;          // Xóa bộ nhớ đệm khi không xử dụng Proxy nữa
            image__ = nullptr;       // gán image_ pointer về nullptr để tránh trỏ đến vùng nhớ không hợp lệ có thể gây lỗi.
            std::cout << "Destructor!\n";
        }      
    }
    void display() {                //  Khi có yêu cầu thực hiện thủ tục display 
        if (!image__) {              //  Nếu Proxy chưa tồn tại trước đó            
            image__ = new ProxyImage(realim__);   // Sao chép thông tin của đối tượng RealImage thật vào ProxyImage
            std::cout << "New Proxy is created!\n";
        }
        else std::cout << "Proxy was created before!\n";
        image__->display();          // Nếu dữ liêu đã có thực hiện thủ tục display từ ProxyImage. 
    }

};

int main() {

    RealImage rl("Picasso", 1500);
    
    
    std::thread t1([]() {
        Image* image = new Proxy(rl);

    // Gọi phương thức display thông qua Proxy lần đầu sẽ tải mới và hiển thị ảnh.
    image->display();

    // Lần gọi tiếp theo sẽ không cần tải lại ảnh mà lấy từ bộ đệm
    image->display();

    delete image;  // Thực chất là delete Proxy trước khi thoát khỏi ứng dụng
        }
    );
    t1.join();
    
    

    Image* image = new Proxy(rl);
   
    // Gọi phương thức display thông qua Proxy lần đầu sẽ tải mới và hiển thị ảnh.
    image->display();

    // Lần gọi tiếp theo sẽ không cần tải lại ảnh mà lấy từ bộ đệm
    image->display();
    image->display();
    image->display();
    delete image;  // Thực chất là delete Proxy trước khi thoát khỏi ứng dụng
    return 0;
}

*/

/*
#include <iostream>
#include <string>
#include <thread>
//Triển khai giao diện Interface chung cho Proxy và ProxyImage
class Image {
public:
    virtual ~Image() {};    // Phải khởi tạo hàm pure Virtual Destructor ở Interface thì mới gọi được Destructor ở các Child Classes
    virtual void display() = 0;
};

//Triển khai lớp ProxyImage kế thừa từ Interface, giao diện giống RealImage 
//và thực hiện việc tải ảnh từ internet(copy dữ liệu từ RealImage)
class ProxyImage : public Image {
public:

    ProxyImage(const std::string& url) {
        // Thực hiện tải ảnh từ url - cấu trúc Contructor này phụ thuộc vào cấu trúc của dữ liệu thật
        std::cout << "Thuc hien tai anh moi!\n";
    }
    void display() {
        // Thực hiện hiển thị ảnh
        std::cout << "Hien thi anh da tai!\n";
    }
};

//Triển khai lớp Proxy kế thừa từ Interface trên, bao gồm một con trỏ tới đối tượng ProxyImage
class Proxy : public Image {
private:
    std::string url_;
    ProxyImage* image_;
public:
    Proxy(const std::string& url) : url_(url), image_(nullptr) {}
    ~Proxy() {
        if (image_) {               // Nếu Proxy đã được khởi tạo
            delete image_;          // Xóa bộ nhớ đệm khi không xử dụng Proxy nữa
            image_ = nullptr;       // gán image_ pointer về nullptr để tránh trỏ đến vùng nhớ không hợp lệ có thể gây lỗi.
            std::cout << "Destructor!\n";
        }
    }
    void display() {                //  Khi có yêu cầu thực hiện thủ tục display 
        if (!image_) {              //  Nếu Proxy chưa tồn tại trước đó sẽ tạo một bộ nhớ đệm  để lưu trữ ảnh đã tải           
            image_ = new ProxyImage(url_);   // Sao chép thông tin của đối tượng RealImage thật tại địa chỉ url vào đối tượng trung gian mới
        }
        image_->display();          // Nếu dữ liêu đã có chỉ cần hiển thị hình ảnh đã có từ bộ đệm. 
    }

};

int main() {
    std::thread t1([]() {
        Image* image = new Proxy("http://example.com/image.jpg");

    // Gọi phương thức display thông qua Proxy lần đầu sẽ tải mới và hiển thị ảnh.
    image->display();

    // Lần gọi tiếp theo sẽ không cần tải lại ảnh mà lấy từ bộ đệm
    image->display();

    delete image;  // Thực chất là delete Proxy trước khi thoát khỏi ứng dụng
        }
    );

    t1.join();
    Image* image = new Proxy("http://example.com/image.jpg");

    // Gọi phương thức display thông qua Proxy lần đầu sẽ tải mới và hiển thị ảnh.
    image->display();

    // Lần gọi tiếp theo sẽ không cần tải lại ảnh mà lấy từ bộ đệm
    image->display();

    delete image;  // Thực chất là delete Proxy trước khi thoát khỏi ứng dụng
    return 0;
}

*/



#include <iostream>
#include <string>

        //Triển khai giao diện Interface chung cho Proxy và ProxyObject
class Interface {
    public:
        virtual ~Interface() {};    // Phải khởi tạo hàm pure Virtual Destructor ở Interface thì mới gọi được Destructor ở các Child Classes
        virtual void operation() = 0;
};

        // Class RealObject quản lý dữ liệu thật 

class RealObject {
    public:
        int attribute1;
        char attribute2;
        bool attribute3;
    RealObject(int att1, char att2, bool att3, int att4, char att5, bool att6) : attribute1(att1), attribute2(att2), attribute3(att3), attribute4(att4), attribute5(att5), attribute6(att6) {}
    private:
        int attribute4;
        char attribute5;
        bool attribute6;
};

        // Triển khai Proxy Object Class chỉ cho truy cập đến 2 thuộc tính của Real Object

 class ProxyObject : public Interface {
    public:
        int attribute1_;
        char attribute2_;
        ProxyObject(const RealObject& rlobj) : attribute1_(rlobj.attribute1), attribute2_(rlobj.attribute2) {};
        void operation() {
            std::cout << "Do something with Proxy Object!\n";
            // Các thao tác trên Proxy Object không làm ảnh hưởng RealObject, qua đó bảo vệ và ẩn đi dữ liệu thật của RealObject
        }
};
 class ProxySevices : public Interface {
    private:
        RealObject rlobj__;
        ProxyObject* pobj;
    public:
        ProxySevices(const RealObject& obj) : rlobj__(obj), pobj(nullptr) {}; 
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
     RealObject object(1, 'A', true, 2, 'B', false);
     Interface* pObject = new ProxySevices(object);
     pObject->operation();
     pObject->operation();
     pObject->operation();
     
     delete pObject;
     return 0;
 }


