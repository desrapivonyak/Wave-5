#include "String.hpp"
#include <cstring>

String::String()
    : m_capacity {0}
    , m_size {0}
    , m_string {new char[m_capacity] {}} 
{}

String::String(const int size)
    : m_capacity {size}
    , m_size {size}
    , m_string {new char[size] {}}
{}

String::String(const char* str) 
{
    m_size = strlen(str);
    m_capacity = strlen(str);
    m_string = new char[m_capacity];
    for (int i = 0; i < m_size; ++i) 
    {
        m_string[i] = str[i];
    }
}

String::String(const String& str) 
{
    m_size = str.m_size;
    m_capacity = str.m_capacity;
    m_string = new char[m_capacity];
    for (int i = 0; i < m_size; ++i) 
    {
        m_string[i] = str.m_string[i];
    }
}

String& String::operator=(const String& str)
{
    if (this == &str) 
    {
        return *this;
    }
    delete[] m_string;
    m_size = str.m_size;
    m_capacity = str.m_capacity;
    m_string = new char[m_capacity];
    for (int i = 0; i < m_size; ++i) 
    {
        m_string[i] = str.m_string[i];
    }
    return *this;
}

String::~String() 
{
    delete[] m_string;
    m_string = nullptr;
}

int String::size() const 
{
    return m_size;
}

int String::capacity() const 
{
    return m_capacity;
}

void String::set_size(const int size)
{
    if (size >= 0)
    {
        m_size = size;
    }
}

char& String::operator[](const int index) 
{
    return m_string[index];
}

const char& String::operator[](const int index) const 
{
    return m_string[index];
}

const char* String::c_str() const
{
    return m_string;
}

bool String::empty() const
{
    return m_size == 0;
}

void String::reserve(const int new_cap)
{
    if (new_cap > m_capacity)
    {
        util(new_cap);
    }
}

void String::shrink_to_fit() 
{
    if(m_capacity > m_size)
    {
        util(m_size);
    }
}

void String::util(const int s)
{
    char* new_str = new char[s];
    for (int i = 0; i < m_size; ++i)
    {
        new_str[i] = m_string[i];
    }
    delete[] m_string;
    m_capacity = s;
    m_string = new_str;
}