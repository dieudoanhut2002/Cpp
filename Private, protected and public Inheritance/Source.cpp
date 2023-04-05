#include <iostream>

class A {
private:
	int aprivate;
protected:
	int aprotected;
public:
	int apublic;	
	A() {};
};
		// PRIVATE INHERITANCE
class B : private A {	
};
class BB : public B {
	B::apublic;	B::aprotected; B::apublic;	// all B attributes were changed to private due to B private inherited from A	
};

		// PROTECTED INHERITANCE

class C : protected A {
};
class CC : public C {
	C::aprivate;				// all C attributes were changed to protected except apprivate was in higher level access modifier 
	C::aprotected;
	C::apublic;
};

		// PUBLIC INHERITANCE

class D : public A {
};
class DD : public D {
	D::aprivate;				// all D attribue keep original access modifier from A in public inheritance
	D::aprotected;
	D::apublic;
};
int main() {
	A a; a.apublic = 1;		// can access only apublic
	B b;					//  can not access any attribute	
	C c;					// can not access any attribute
	D d; d.apublic = 2;		// can access public member
	
	return 0;
}

/* CONCLUSION:	All lower level access attribues were changed their access modifier to private or protected due to
				which inheritance implementing: private or protected. 
				Public Inheritance keep the original access modifier		*/