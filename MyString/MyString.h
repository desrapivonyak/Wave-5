// #ifndef MY_STRING
// #define MY_STRING

// #include <string>
// #include <iostream>

// class MyString 
// {
// public:
//     MyString();
//     MyString(const char*);
//     MyString(const std::string&);
//     MyString(const MyString&);
//     MyString& operator=(const char*);
//     MyString& operator=(const MyString&);
//     char& operator[](const size_t);
//     const char operator[](const size_t) const;
//     ~MyString();
//     size_t size() const;
//     const char* c_str() const;
//     bool empty() const;
//     void reset();
//     MyString& operator+=(const char*);
//     MyString& operator+=(const std::string&);
//     MyString& operator+=(const MyString&);

//     // friend MyString operator+(const MyString&, const char*);
//     // friend MyString operator+(const MyString&, const std::string&);
//     // friend MyString operator+(const MyString&, const MyString&);
//     // friend MyString operator+(const char*, const MyString&);
//     // friend MyString operator+(const std::string&, const MyString&);

//     friend std::ostream& operator<<(std::ostream&, const MyString&);
//     friend std::istream& operator>>(std::istream&, MyString&);
// private:
//     size_t m_size;
//     char* m_ptr;
// };

// #endif