#include "Person.h"
#include <iostream>
using namespace std;

//default constructor should be here

Person Person::operator+(Person p) 
{ 
	return Person(this->name_ + p.name_); 
}

Person& Person::operator=(const Person& p) 
{ 
	this->name_ = p.name_; this->id_ = p.id_; return *this; 
}

Person::~Person()
{
	cout << "Destructor\n";
}
