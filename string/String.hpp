#pragma once

class String {
//ctors and dtor
public:
    String() = default; //default ctor
    explicit String(const int); //ctor with parameter initializing size
    String(const char*); //ctor with parameter initializing chr*
    String(const String&); //copy ctor
    String& operator=(const String&); //copy assigment operator
    ~String(); //dtor
public:
    int size() const;
    int capacity() const;
    void set_size(const int);
    char& operator[](const int);
    const char& operator[](const int) const;
    const char* c_str() const;
    bool empty() const;
    void reserve(const int);
    void shrink_to_fit();
//utility function
private:
    void utility_function(const int);
    void duplicate(const String& arr);
//data members
private:
    struct { int size; char* ptr; } dyn_str;
    union {
        char onstack[16];
        decltype(dyn_str) str;
    } m_string;
};