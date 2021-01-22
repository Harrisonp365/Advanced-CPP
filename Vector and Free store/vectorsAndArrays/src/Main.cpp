#include <iostream>
#include <vector>

using namespace std;
/*
struct X {
	int val;

	void out(const string& s, int nv) { cerr << this << "->" << s << ": " << val << "(" << nv << " )\n"; }

	X() { out("X()", 0); val = 0; } // default constructor
	X(int v) { val = v; out("X(int)", v); }
	X(const X& x) { val = x.val; out("X(X&)", x.val); } // copy constructor
	X& operator=(const X& a) { out("X::operator=()", a.val); val = a.val; return *this; } // copy assignment
	~X() { out("~X()", 0); }
};

X glob(2); //global variable
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& refTo(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };
*/
int main()
{	/*
	X loc{ 4 }; //local variable
	X loc2{ loc }; //copy constructor
	loc = X{ 5 }; // copy assignment
	loc2 = copy(loc); //call by val and return
	loc2 = copy2(loc);
	X loc3{ 6 };
	X& r = refTo(loc); //call by reference and return
	delete make(7);
	delete make(8);
	vector<X> v(4); // default values
	XX loc4;
	X* p = new X{ 9 }; // an X on heap
	delete p;
	X* pp = new X[5]; // array of x's on heap
	delete[] pp;
	*/
	//Basic pointer arithmatic
	const int max = 10;
	int ar[max];
	int* p = &ar[5]; //points to middle of array '5'

	//subscript
	*p = 7; // index 5 = 7
	p[2] = 6; // 2 indexs up from 5 = 6. index 7 = 6
	p[-3] = 9; // 3 indexs down from 5 = 9. index 2 = 9
	p += 2; // p now points to index 7 not 5
	p -= 5; // p now points to index 2 not 5
	//print value of all elements
	for (int* p = &ar[0]; p < &ar[max]; ++p) cout << *p << '\n';
	//backwards
	for (int* p = &ar[max-1]; p >= &ar[0]; --p) cout << *p << '\n';
}	
