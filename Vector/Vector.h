#pragma once

#include <iostream>
#include <initializer_list>

class Vector
{
//Ctors, Assigment operators and dtor
public:
	Vector(); //default ctor
	explicit Vector(int); //ctor with one parameter
	Vector(const Vector&); //copy ctor
	Vector& operator=(const Vector&); //copy assigment operator
	~Vector(); //dtor
//Other member functions
public:
	void set_size(int);
	void set_capacity(int);
	int get_size() const;
	int get_capacity() const;
	int& operator[](int);
	void push_back(const int&);
	void pop_back();
//data members
private:
	int m_size;
	int m_capacity;
	int* m_array;
};