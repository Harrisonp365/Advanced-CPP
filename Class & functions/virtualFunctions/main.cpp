//#include "std_lib_facilities.h"
#include <iostream>

using namespace std;

struct B {
	virtual void f() const { cout << "B::f"; }
	void g() const { cout << "B::g"; } // not virtual
};

struct D : B {
	void f() const { cout << "D::f"; } // overrides B::f
	void g() { cout << "D::g"; } // error: no virtual B::g to override
};

struct DD : D {
	void f() { cout << "DD::f"; } // doesnt override D::f because not const
	void g() const { cout << "DD::g"; } // error no virtual D::g to override
};

void call(const B& b)
{
	b.f();
	b.g();
}


int main()
{
	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	b.f();
	b.g();

	d.f();
	d.g();

	dd.f();
	dd.g();

	return 0;
}