#include "MyString.hpp"
#include <cstring>

// Constructors
MyString::MyString() : m_on_stack{true} { m_string.onstack[0] = '\0'; }

MyString::MyString(const char *c_arr) : m_on_stack{true} {
  size_t length = strlen(c_arr);
  if (length > 16) {
    m_string.ptr = new char[length + 1];
    m_on_stack = false;
    strcpy(m_string.ptr, c_arr);
  } else {
    strcpy(m_string.onstack, c_arr);
  }
}

MyString::MyString(const std::string &str) : MyString(str.c_str()) {}

MyString::MyString(const MyString &other) : m_on_stack{other.m_on_stack} {
  if (!m_on_stack) {
    size_t length = strlen(other.m_string.ptr);
    m_string.ptr = new char[length + 1];
    strcpy(m_string.ptr, other.m_string.ptr);
  } else {
    strcpy(m_string.onstack, other.m_string.onstack);
  }
}

MyString::MyString(MyString &&other) : m_on_stack{other.m_on_stack} {
  if (!m_on_stack) {
    m_string.ptr = other.m_string.ptr;
    other.m_string.ptr = nullptr;
  } else {
    strcpy(m_string.onstack, other.m_string.onstack);
  }
  other.reset();
}

// Copy assigment operator
MyString &MyString::operator=(const MyString &other) {
  if (this != &other) {
    reset();
    size_t length = strlen(other.m_string.ptr);
    if (!other.m_on_stack) {
      m_string.ptr = new char[length + 1];
      strcpy(m_string.ptr, other.m_string.ptr);
      m_on_stack = false;
    } else {
      strcpy(m_string.onstack, other.m_string.onstack);
      m_on_stack = true;
    }
  }
  return *this;
}

MyString &MyString::operator=(const char *str) { return assign(str); }

MyString &MyString::operator=(const std::string &str) {
  return assign(str.c_str());
}

MyString &MyString::operator=(MyString &&other) {
  if (this != &other) {
    reset();
    size_t length = strlen(other.m_string.ptr);
    if (!other.m_on_stack) {
      m_string.ptr = new char[length + 1];
      strcpy(m_string.ptr, other.m_string.ptr);
      m_on_stack = false;
    } else {
      strcpy(m_string.onstack, other.m_string.onstack);
      m_on_stack = true;
    }
    other.reset();
  }
  return *this;
}

// Destructor
MyString::~MyString() {
  if (!m_on_stack) {
    delete[] m_string.ptr;
  }
}

// Other member functions
char &MyString::operator[](const size_t index) {
  if (index < 0 &&
      index > std::max(strlen(m_string.onstack), strlen(m_string.ptr))) {
    throw std::out_of_range("Index out of range.");
  }
  return !m_on_stack ? m_string.ptr[index] : m_string.onstack[index];
}

const char &MyString::operator[](const size_t index) const {
  if (index < 0 &&
      index > std::max(strlen(m_string.onstack), strlen(m_string.ptr))) {
    throw std::out_of_range("Index out of range.");
  }
  return !m_on_stack ? m_string.ptr[index] : m_string.onstack[index];
}

size_t MyString::size() const {
  return m_on_stack ? strlen(m_string.onstack) : strlen(m_string.ptr);
}

const char *MyString::c_str() const {
  return m_on_stack ? m_string.onstack : m_string.ptr;
}

bool MyString::empty() const { return size() == 0; }

void MyString::reset() {
  if (!m_on_stack) {
    delete[] m_string.ptr;
    m_string.ptr = nullptr;
  }
  m_on_stack = true;
}

MyString &MyString::operator+=(const char *cstr) {
  size_t len = strlen(cstr);
  size_t total_len = size() + len;
  if (m_on_stack && total_len <= 16) {
    strcat(m_string.onstack, cstr);
  } else {
    char *new_str = new char[total_len + 1];
    strcpy(new_str, c_str());
    strcat(new_str, cstr);
    reset();
    m_string.ptr = new_str;
    m_on_stack = false;
  }
  return *this;
}

MyString &MyString::operator+=(const MyString &str) {
  operator+=(str.c_str());
  return *this;
}

MyString &MyString::operator+=(const std::string &str) {
  operator+=(str.c_str());
  return *this;
}

MyString &MyString::assign(const char *str) {
  reset();
  size_t length = strlen(str);
  if (length > 16) {
    m_string.ptr = new char[length + 1];
    m_on_stack = false;
    strcpy(m_string.ptr, str);
  } else {
    strcpy(m_string.onstack, str);
  }
  return *this;
}

// other functions

std::istream &operator>>(std::istream &is, MyString &str) {
  char buffer[1024];
  is >> buffer;
  str = buffer;
  return is;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
  os << str.c_str();
  return os;
}