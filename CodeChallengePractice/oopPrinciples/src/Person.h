#pragma once
#include <iostream>
using namespace std;

class Person {
private:
	string name_;
	int id_;
public:
	Person(string name = "", int id = 0000) : name_{ name } { id_ = id; }
	string GetName() { return name_; }
	Person operator+(Person p);
	Person& operator=(const Person& p);
	~Person();
};