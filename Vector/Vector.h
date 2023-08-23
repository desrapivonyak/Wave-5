#pragma once

#include <iostream>

class Vector
{
//Ctors, Assigment operators and dtor
public:
	Vector(); //default ctor
	explicit Vector(const int); //ctor with one parameter
	Vector(const Vector&); //copy ctor
	Vector& operator=(const Vector&); //copy assigment operator
	~Vector(); //dtor
//Other member functions
public:
	void set_size(const int);
	void set_capacity(const int);
	int get_size() const;
	int get_capacity() const;
	int& operator[](const int);
	void push_back(const int&);
	void pop_back();
	bool empty() const;
	void resize(const int);
	void shrink_to_fit();
private:
	void util(const int);
//data members
private:
	int m_size;
	int m_capacity;
	int* m_array;
};