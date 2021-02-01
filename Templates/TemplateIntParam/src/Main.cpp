#include <iostream>

using namespace std;

template<typename T, int N> struct array
{
	T elem[N]; // holds elements in member array 
	// rely on default constructor and destructor and assignment
	T& operator[] (int n); // access: return reference
	const T& operator[] (int n) const;

	T* data() { return elem; } // conversion to T*
	const T* data() const { return elem; }

	int size() const { return N;}
};

array<int, 256> gb;
array<double, 6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
const int max = 1024;

void some_fct(int n)
{
	array<char, max> loc;
	array<char, n> oops; // error: the value of N not known by the compiler
	////.......
	array<char, max> loc2 = loc; // make backup copy
	loc = loc2; // restore
}

// Reason to use array.
// They can be more efficent that vectors due to knowing size of at compile time, compiler can allocate static memory
// Use when you are unable to use free store, some embedded programs may need this

// CLASS TEMPALTES

array<char, 1024> buf; // T is char and N is 1024
array<double, 10> b2; // T is double and N is 10

template<class T, int N> void fill(array<T, N>& b, const T& val)
{
	for (int i = 0; i < N; ++i)
		b[i] = val;
}

void f()
{
	fill(buf, 'x'); // fill<char, 1024>(buf, 'x);

	fill(b2, 0.0); // fill<double, 10>(b2, 0.0);
}