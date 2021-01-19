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
	vector v(5);
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
	return 0;
}
