#include <iostream>
#include <vector>

using namespace std;

class vector {
public:
	vector(int s); // constructor allocate s double, stores s in sz
	int size() const { return sz; } // current size

private:
	int sz; // size
	double* elem; // pointer to first element (double)
};


int main()
{

	return 0;
}

vector::vector(int s)
{

}
