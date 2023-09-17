#include "String.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>

// String::String(const int size)
// {
//     if(size > 16) {
//         dyn_str.size = size;
//         dyn_str.ptr = new char[size];
//     }
// }

String::String(const char* arr) 
{
    int length = strlen(arr);
    if (length <= 16)
    {
        m_string.onstack[length] = '\0';
        memcpy(m_string.onstack, arr, length);
    } 
    else
    {
        dyn_str.size = length;
        dyn_str.ptr = new char[length + 1];
        strcpy(dyn_str.ptr, arr);
    }
}

// String::String(const String& arr) 
// {
//     duplicate(arr);
// }

// String& String::operator=(const String& arr)
// {
//     if (this != &arr) 
//     {
//         duplicate(arr);
//     }
//     return *this;
// }

String::~String() 
{
    if (dyn_str.ptr)
    {
        delete[] dyn_str.ptr;
        dyn_str.ptr = nullptr;
    }
}

int String::size() const 
{
    if(dyn_str.ptr)
    {
        return dyn_str.size;
    }
    return strlen(m_string.onstack);
}

// int String::capacity() const 
// {
//     if (m_string.str.ptr)
//     {
//         return m_string.str.m_capacity;
//     }
//     return 16;
// }

// char& String::operator[](const int index) 
// {
//     if (index < 0)
//     {
// 		throw std::out_of_range("Index Out of range");
//     }

// 	if (m_string.str.ptr) 
//     {
//         if(index >= m_string.str.m_size)
//         {
//             throw std::out_of_range("Index Out of range");
//         }
//         return m_string.str.ptr[index];
//     }
//     return m_string.onstack[index];
// }

// const char& String::operator[](const int index) const 
// {
//     if (index < 0)
//     {
// 		throw std::out_of_range("Index Out of range");
//     }
    
// 	if (m_string.str.ptr) 
//     {
//         if(index >= m_string.str.m_size)
//         {
//             throw std::out_of_range("Index Out of range");
//         }
//         return m_string.str.ptr[index];
//     }
//     return m_string.onstack[index];
// }

const char* String::c_str() const
{
    if (dyn_str.ptr)
    {
        return dyn_str.ptr;
    }
    return m_string.onstack;
}

// bool String::empty() const
// {
//     if (m_string.str.ptr) 
//     {
//         return m_string.str.m_size == 0;
//     }
//     return strlen(m_string.onstack) == 0;
// }

// void String::reserve(const int new_cap)
// {
//     if (m_string.str.ptr)
//     {
//         if (new_cap > m_string.str.m_capacity)
//         {
//             utility_function(new_cap);
//         }
//     }
// }

// void String::shrink_to_fit() 
// {
//     if (m_string.str.ptr)
//     {
//         if (m_string.str.m_size < m_string.str.m_capacity)
//         {
//             utility_function(m_string.str.m_size);
//         }
//     }
// }

// void String::utility_function(const int s)
// {
//     char* new_str = new char[s];
//     for (int i = 0; i < m_string.str.m_size; ++i)
//     {
//         new_str[i] = m_string.str.ptr[i];
//     }
//     delete[] m_string.str.ptr;
//     m_string.str.m_capacity = s;
//     m_string.str.ptr = new_str;
// }

// void String::duplicate(const String& arr) 
// {
//     if (arr.m_string.str.ptr) 
//     {
//         if (m_string.str.ptr)
//         {
//             delete[] m_string.str.ptr;
//         }
//         m_string.str.m_capacity = arr.m_string.str.m_capacity;
//         m_string.str.m_size = arr.m_string.str.m_size;
//         m_string.str.ptr = new char[m_string.str.m_capacity];
//         for (int i = 0; i < m_string.str.m_capacity; ++i)
//         {
//             m_string.str.ptr[i] = arr.m_string.str.ptr[i];
//         }
//     }
//     else
//     {
//         if (m_string.str.ptr)
//         {
//             delete[] m_string.str.ptr;
//         }
//         for (int i = 0; i < strlen(arr.m_string.onstack); ++i)
//         {
//             m_string.onstack[i] = arr.m_string.onstack[i];
//         }
//     }
// }