#include <iostream>

using namespace std;

class B {
public:
	virtual void f() = 0; // Pure virtual functions and abstract class mean you can not create an instance of B
	virtual void g() = 0;
};

class D1 : public B {
public:
	void f() override;
	void g() override;
};

class D2 : public B {
public:
	void f() override;
	// no g()
};

class D3 : public D2 {
public:
	void g() override;
};

int main()
{
	//B b; // not ok this will error you can not create B as it is abstract
	D1 d1; // This is ok
	//D2 d2; // Error D2 is still abstract
	D3 d3; // This is ok

	return 0;

}