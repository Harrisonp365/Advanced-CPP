#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person p1;
	Person p2("A");
	Person p3("Allen", 1234);

	p1 = p2 + p3;
	p2 = p3;
	return 0;
}