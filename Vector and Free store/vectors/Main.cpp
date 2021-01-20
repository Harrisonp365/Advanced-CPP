#include <iostream>

using namespace std;

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[s] }  // constructor allocate s double, stores s in sz
	{
		for (int i = 0; i < s; ++i) elem[i] = 0;
	} 
	
	~vector() { delete[] elem; } //destructor
	int size() const { return sz; } // current size

	double get(int n) const { return elem[n]; } //read
	void set(int n, double v) { elem[n] = v; } // write
private:
	int sz; // size
	double* elem; // pointer to first element (double)
};

int main()
{
	//Vector class
	/* vector v(5);
	for (int i = 0; i < v.size(); ++i)
	{
		v.set(i, 1.1 * i);
		std::cout << "v[" << i << "]==" << v.get(i) << "\n";
	}

	vector* f(int s)
	{
		vector* p = new vector(s); // allocate a vector on free storage
		//fill *p
		return p;
	}

	void ff()
	{
		vector* q = f(4);
		// use *q
		delete q; // free vector on heap 
	}
	*/
	// Void pointers

	void* pv1 = new int; //converts int* to void*
	void* pv2 = new double[10]; // converts double* to void*

	void f(void* pv)
	{
		void* pv2 = pv; //copying is OK 
		double* pd = pv; // error cant convert void* to double*
		*pv = 7;         // error cant dereference a void* we don't know what type it points to

		pv[2] = 9;      //error cant subscript a void*
		int* pi = static_cast<int*>(pv); // OK, explicit conversion
	}

	//Reinterprit_cast and const_cast examples- Try not to use these

	Register* in = reinterpret_cast<Register*>(0xff); //tells a certain part of memory beginning with 0xff is to be a register

	void f(const Buffer* p)
	{
		Buffer* b = const_cast<Buffer*>(p); // cast away const
	}
	return 0;
}
