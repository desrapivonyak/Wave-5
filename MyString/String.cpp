#include "MyString.hpp"
#include <cstring>

//Constructors
MyString::MyString()
{
    m_string.ptr = nullptr;
}

MyString::MyString(const char* c_arr) 
{
    size_t length = strlen(c_arr);
    if (length < 16)
    {
        std::memcpy(m_string.onstack, c_arr, length + 1);
        m_string.onstack[length] = '\0';
        m_string.ptr = nullptr;
    } 
    else
    {
        m_string.ptr = new char[length + 1];
        std::memcpy(m_string.ptr, c_arr, length + 1);
    }
}

MyString::MyString(const std::string& str)
    : MyString(str.c_str())
{
}

MyString::MyString(const MyString& other)
{
    size_t length = strlen(other.m_string.ptr);
    if (other.m_string.ptr)
    {
        m_string.ptr = new char[length + 1];
        std::memcpy(m_string.ptr, other.m_string.ptr, length + 1);
    }
    else
    {
        std::memcpy(m_string.onstack, other.m_string.onstack, length + 1);
        m_string.ptr = nullptr;
    }
}

//Copy assigment operators
MyString& MyString::operator=(const MyString& other)
{
    if(this != &other)
    {
        if (other.m_string.ptr)
        {
            size_t length = strlen(other.m_string.ptr);
            m_string.ptr = new char[length];
            for (size_t i = 0; i < length; ++i)
            {
                m_string.ptr[i] = other.m_string.ptr[i];
            }
        }
        else
        {
            size_t length = strlen(other.m_string.onstack);
            m_string.onstack[length] = '\0';
            memcpy(m_string.onstack, other.m_string.onstack, length);
        }
    }
    return *this;
}

MyString& MyString::operator=(const char* cstr)
{
    size_t length = strlen(cstr);
    if (length <= 16)
    {
        m_string.onstack[length] = '\0';
        memcpy(m_string.onstack, cstr, length);
    } 
    else
    {
        m_string.ptr = new char[length + 1];
        strcpy(m_string.ptr, cstr);
    }
    return *this;
}

MyString& MyString::operator=(const std::string& str)
{
    size_t length = str.size();
    if (length < 16)
    {
        m_string.onstack[length] = '\0';
        for (size_t i = 0; i < length; ++i)
        {
            m_string.onstack[i] = str[i];
        }
    }
    else
    {
        m_string.ptr = new char[length];
        for (size_t i = 0; i < length; ++i)
        {
            m_string.ptr[i] = str[i];
        }
    }
    return *this;
}

//Destructor
MyString::~MyString()
{
    if (m_string.ptr)
    {
        delete[] m_string.ptr;
    }
}

//Other member functions
char& MyString::operator[](const size_t index) 
{
    if (index < 0 && index > std::max(strlen(m_string.onstack), strlen(m_string.ptr)))
    {
        throw std::out_of_range("Index out of range.");
    }
    return m_string.ptr ? m_string.ptr[index] : m_string.onstack[index];
}

size_t MyString::size() const
{
    return std::max(strlen(m_string.onstack), strlen(m_string.ptr));
}

const char* MyString::c_str() const
{
    return m_string.ptr ? m_string.ptr : m_string.onstack;
}

bool MyString::empty() const
{
    return size() == 0;
}

void MyString::reset() 
{
    if (m_string.ptr)
    {
        delete[] m_string.ptr;
        m_string.ptr = nullptr;
    }
    else 
    {
        m_string.onstack[0] = '\0';
    }
}

// MyString& MyString::operator+=(const char* cstr)
// {
//     size_t new_size = strlen(cstr) + m_size;
//     char* new_str = new char[new_size];
//     for(size_t i = m_size - 1; i < new_size; ++i)
//     {
//         new_str[i] = cstr[i];
//     }
//     delete[] m_ptr;
//     m_size = new_size;
//     m_ptr = new_str;
//     return *this;
// }

// MyString& MyString::operator+=(const MyString& str)
// {
//     MyString new_str;
//     size_t new_size = m_size + str.size();
//     new_str = new char[new_size];
//     for(size_t i = str.size() - 1; i < new_size; ++i)
//     {
//         new_str.m_ptr[i] = str.m_ptr[i];
//     }
//     delete[] m_ptr;
//     m_size = new_size;
//     m_ptr = new_str.m_ptr;
//     return *this;
// }

// MyString& MyString::operator+=(const std::string& str)
// {
//     size_t new_size = m_size + str.size();
//     char* new_str = new char[new_size];
//     for(size_t i = str.size() - 1; i < new_size; ++i)
//     {
//         new_str[i] = str[i];
//     }
//     delete[] m_ptr;
//     m_size = new_size;
//     m_ptr = new_str;
//     return *this;
// }

//friend functions
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.c_str();
    return os;
}

std::istream& operator>>(std::istream& in, MyString& str)
{
    if (str.m_string.ptr)
    {
        in >> str.m_string.ptr;
    }
    else
    {
        in >> str.m_string.onstack;
    }
    return in;
}