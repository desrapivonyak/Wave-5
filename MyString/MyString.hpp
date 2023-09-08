#ifndef MY_STRING
#define MY_STRING

#include <string>
#include <iostream>

class MyString 
{
public:
    MyString();
    explicit MyString(const char*);
    explicit MyString(const std::string&);
    MyString(const MyString&);
    MyString(MyString&&);

    MyString& operator=(const MyString&);
    MyString& operator=(const char*);
    MyString& operator=(const std::string&);
    MyString& operator=(MyString&&);

    char& operator[](const size_t);
    const char& operator[](const size_t) const;

    ~MyString();

public:
    size_t size() const;
    const char* c_str() const;
    bool empty() const;
    void reset();

    MyString& operator+=(const char*);
    MyString& operator+=(const std::string&);
    MyString& operator+=(const MyString&);

private:
    MyString& assign(const char*);

private:
    bool m_on_stack;
    union
    {
        char onstack[16];
        char* ptr;
    } m_string;
};

std::ostream& operator<<(std::ostream&, const MyString&);
std::istream& operator>>(std::istream&, MyString&);

#endif