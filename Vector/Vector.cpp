#include "Vector.h"

Vector::Vector()
	: m_size{ 0 }
	, m_capacity{ 0 }
	, m_array{ nullptr }
{
}
	
Vector::Vector(int size)
	: m_size{ size }
	, m_capacity{ size }
	, m_array{ new int[size]{}}
{
}
	
Vector::Vector(const Vector& other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_array = new int[other.m_capacity];
	for(int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete m_array;
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_array = new int[other.m_capacity];
	for(int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
	return *this;
}
	
Vector::~Vector()
{
	delete[] m_array;
	m_array = nullptr;
}

void Vector::set_size(int size) {
	if (size > 0) {
		m_size = size;
	}
}

void Vector::set_capacity(int capacity) {
	if (capacity > 0) {
		m_capacity = capacity;
	}
}

int Vector::get_size() const {
	return m_size;
}

int Vector::get_capacity() const {
	return m_capacity;
}

int& Vector::operator[](int index) {
	return m_array[index];
}

void Vector::push_back(const int& elem) {
	if (get_capacity() == get_size()) {
		if (get_capacity() == 0) {
			set_capacity(1);
		} else {
			set_capacity(2 * get_capacity());
		}
		int* new_data = new int[get_capacity()];
		for (size_t i = 0; i < m_size; ++i) {
			new_data[i] = m_array[i];
		}
		delete[] m_array;
		m_array = new_data;
	}
	m_array[m_size++] = elem;
}

void Vector::pop_back() {
	--m_size;
}