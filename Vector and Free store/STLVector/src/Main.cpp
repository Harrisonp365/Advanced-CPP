#include <iostream>
using namespace std;

template<typename T> class allocator {
public:
	//..
	T* allocate(int n); //allocate space for n Objects of type T
	void deAlloccate(T* p, int n); // deallocate n objects of Type T starting at p

	void construct(T* p, const T& v); // construct a T with the value V in P
	void destroy(T* p); // destroy the T in P
};

template<typename T, typename A = allocator<T>> 
class vector {
public:
	A alloc; // use allocate to handle memory for elements
	vector() :sz{0}, elem{nullptr}, space{0}{}
	explicit vector(int s) :sz{ s }, elem{ new T[s] }, space{ s }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0; //init
	}
	vector(const vector&);
	vector& operator=(const vector&);

	vector(vector&&);
	vector& operator=(vector&&);
	~vector() { delete[] elem; }

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
	int capacity() const { return space; }
	void resize(int newSize);
	void pushBack(const T& d);
	void reserve(int newalloc);
	
	
private:
	int sz;
	T* elem;
	int space;
};

template<typename T, typename A>
void vector<T, A>::reserve(int newalloc)
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

