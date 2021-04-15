#include <iostream>
#include "Person.h"
#include "Students.h"
using namespace std;

int main()
{
	Students s1("cba", 321, "IT");
	Person* p1 = &s1;
	p1->func();
	return 0;
}