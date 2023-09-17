// #include "MyString.h"
// #include <cstring>

// //Constructors
// MyString::MyString() 
//     : m_size{1}
//     , m_ptr{new char[m_size]}
// {
// }

// MyString::MyString(const char* c_arr) 
//     : m_size {strlen(c_arr)}
// {
//     m_ptr = new char[m_size];
//     strcpy(m_ptr, c_arr);
// }

// MyString::MyString(const std::string& str)
//     : m_size {str.size()}
// {
//     m_ptr = new char[m_size];
//     for (int i = 0; i < m_size; ++i)
//     {
//         m_ptr[i] = str[i];
//     }
// }

// MyString::MyString(const MyString& other)
//     : m_size {other.m_size}
// {
//     m_ptr = new char[m_size];
//     for(int i = 0; i < m_size; ++i)
//     {
//         m_ptr[i] = other.m_ptr[i];
//     }
// }

// //Copy assigment operators
// MyString& MyString::operator=(const MyString& other)
// {
//     if(this != &other)
//     {
//         m_size = other.m_size;
//         m_ptr = new char[m_size];
//         for (size_t i = 0; i < m_size; ++i)
//         {
//             m_ptr[i] = other.m_ptr[i];
//         }
//     }
//     return *this;
// }

// MyString& MyString::operator=(const char* cstr)
// {
//     m_size = strlen(cstr);
//     m_ptr = new char[m_size];
//     for (size_t i = 0; i < m_size; ++i)
//     {
//         m_ptr[i] = cstr[i];
//     }
//     return *this;
// }
// //Destructor
// MyString::~MyString()
// {
//     delete[] m_ptr;
// }

// //Other member functions
// char& MyString::operator[](const size_t index) 
// {
//     if(index < 0 && index > m_size)
//     {
//         throw std::out_of_range("Index out of range.");
//     }
//     return m_ptr[index];
// }

// size_t MyString::size() const
// {
//     return m_size;
// }

// const char* MyString::c_str() const
// {
//     return m_ptr;
// }

// bool MyString::empty() const
// {
//     return m_size == 0;
// }

// void MyString::reset() 
// {
//     if (m_ptr)
//     {
//         m_ptr[0] = '\0';
//     }
// }

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

// //friend functions
// std::ostream& operator<<(std::ostream& os, const MyString& str)
// {
//     os << str.m_ptr;
//     return os;
// }

// std::istream& operator>>(std::istream& in, MyString& str)
// {
//     in >> str.m_ptr;
//     return in;
// }

// // MyString operator+(const char* cstr, const MyString& str)
// // {
// //     MyString new_str {cstr};
// //     size_t new_size = strlen(cstr) + str.size();
// //     new_str = new char[new_size];
// //     for(size_t i = strlen(cstr) - 1; i < new_size; ++i)
// //     {
// //         //new_str.m_ptr[i] = str[i - strlen(cstr) - 1];
// //     }
// //     return new_str;
// // }

// // MyString operator+(const MyString& str, const char* cstr)
// // {
// //     MyString new_str {str};
// //     size_t new_size = strlen(cstr) + str.size();
// //     new_str = new char[new_size];
// //     for(size_t i = str.size() - 1; i < new_size; ++i)
// //     {
// //         new_str.m_ptr[i] = cstr[i];
// //     }
// //     return new_str;
// // }