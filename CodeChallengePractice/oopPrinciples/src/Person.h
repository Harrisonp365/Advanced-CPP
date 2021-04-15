#pragma once
#include <iostream>
using namespace std;

class Person {
protected:
	string name_;
	int id_;
public:
	Person(string name = "", int id = 0000) : name_{ name } { id_ = id; } //constructor
	Person(const Person& person) { this->name_ = person.name_; this->id_ = person.id_; } //copy constructor
	string GetName() { return name_; } //func
	Person operator+(Person p); // operator overload
	Person& operator=(const Person& p); //operator overload
	virtual void func(); //polymorphism example
	~Person(); //destructor
};