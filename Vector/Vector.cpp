#include "Vector.h"

Vector::Vector()
	: m_size{ 0 }
	, m_capacity{ 0 }
	, m_array{ nullptr }
{
}
	
Vector::Vector(const int size)
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
	for (int i = 0; i < m_size; ++i)
	{
		m_array[i] = other.m_array[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] m_array;
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_array = new int[other.m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		m_array[i] = other.m_array[i];
	}
	return *this;
}
	
Vector::~Vector()
{
	delete[] m_array;
	m_array = nullptr;
}

void Vector::set_size(int size)
{
	if (size > 0)
	{
		m_size = size;
	}
}

void Vector::set_capacity(int capacity)
{
	if (capacity > 0)
	{
		m_capacity = capacity;
	}
}

int Vector::get_size() const
{
	return m_size;
}

int Vector::get_capacity() const
{
	return m_capacity;
}

int& Vector::operator[](const int index)
{
	return m_array[index];
}

void Vector::push_back(const int& elem)
{
	if (m_capacity == m_size)
	{
		if (m_capacity == 0)
		{
			m_capacity = 1;
		}
		resize(m_size + 1);
	}
	m_array[m_size++] = elem;
}

void Vector::pop_back()
{
	--m_size;
}

bool Vector::empty() const
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}

void Vector::resize(const int new_size)
{
	if (new_size > m_capacity)
	{
		m_capacity = 2 * m_capacity;
	}
	util(new_size);
}

void Vector::shrink_to_fit()
{
	if (m_size < m_capacity)
	{
		util(m_size);
	}
}

void Vector::util(const int s)
{
	int* new_data = new int[s];
	for (size_t i = 0; i < m_size; ++i)
	{
		new_data[i] = m_array[i];
	}
	delete[] m_array;
	m_array = new_data;
	m_capacity = m_size;
}