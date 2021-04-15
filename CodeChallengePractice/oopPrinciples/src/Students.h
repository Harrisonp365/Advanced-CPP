#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class Students : public Person
{
private:
	string degree_;
public:
	Students(string name, int id, string deg) : degree_{ deg }, Person(name, id) {}
	void func(); // same func as Person class
	~Students();
};