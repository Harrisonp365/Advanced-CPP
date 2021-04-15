#include "Students.h"
#include "Person.h"
#include <iostream>
using namespace std;



void Students::func()
{
	cout << "func from students\n";
}

Students::~Students()
{
	cout << "Destructor Students\n";
}