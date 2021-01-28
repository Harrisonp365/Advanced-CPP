#include <iostream>
using namespace std;

class vector
{
	
public:
	vector() :sz{0}, elem{nullptr}, space{0}{}
	explicit vector(int s) :sz{ s }, elem{ new double[s] }, space{ s }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0; //init
	}
	vector(const vector&);
	vector& operator=(const vector&);

	vector(vector&&);
	vector& operator=(vector&&);
	~vector() { delete[] elem; }

	double& operator[](int n) { return elem[n]; }
	const double& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
	int capacity() const { return space; }
	void resize(int newSize);
	void pushBack(double d);
	void reserve(int newalloc);
	
	
private:
	int sz;
	double* elem;
	int space;
};

void vector::reserve(int newalloc)
{
	if (newalloc <= space) return;
	double* p = new double[newalloc];
	for (int i = 0; i < sz; ++i) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = newalloc;
}

void vector::resize(int newSize)
{
	reserve(newSize);
	for (int i = sz; i < newSize; ++i) elem[i] = 0;
	sz = newSize;
}

void vector::pushBack(double d)
{
	if (space == 0)
		reserve(8); //start space with 8 elements
	else if (sz == space)
		reserve(2 * space); // get more space ( double the space)
	elem[sz] = d; // add d at end
	++sz; //increase the size 
}

vector& vector::operator=(const vector& a)
//like copy constructor but handles old elements
{
	if (this == &a) return *this;
	if (a.sz <= space)
	{
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}
	double* p = new double[a.sz];
	for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i];
	delete[] elem;
	space = sz = a.sz;
	elem = p;
	return *this;
}

vector::vector(vector&& a) : sz{a.sz}, elem{a.elem}
{
	a.sz = 0;
	a.elem = nullptr;
}

vector& vector::operator=(vector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

int main()
{


	return 0;
}