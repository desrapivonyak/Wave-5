#include "MyString.hpp"
#include <iostream>

int main() {
  MyString str;
  std::cout << str << "Default ctor worked!" << std::endl;

  MyString str11{"Hello"};
  std::cout << "\nchar* ctor on stack worked" << std::endl;
  std::cout << str11 << std::endl;

  MyString str1{"Helloօօօօօօօօօօօօ"};
  std::cout << "\nchar* ctor on heap worked" << std::endl;
  std::cout << str1.c_str() << std::endl;

  std::string s = "World";
  MyString str2{s};
  std::cout << "\nstd::string ctor on stack worked" << std::endl;
  std::cout << str2 << std::endl;

  std::string s1 = "Worlddddddddddddddddd";
  MyString str3{s1};
  std::cout << "\nstd::string ctor on heap worked" << std::endl;
  std::cout << str3 << std::endl;

  str2[2] = 'b';
  std::cout << "\nIndexing worked\n" << str2 << std::endl;
  std::cout << "c_str " << str2.c_str() << std::endl;
  std::cout << "Is empty " << str2.empty() << std::endl;

  MyString str4{str2};
  std::cout << "\nCopy ctor" << std::endl;
  std::cout << str4 << std::endl;
  std::cout << "Size " << str4.size() << std::endl;

  MyString str5;
  str5 = str3;
  std::cout << "\nCopy assigment operator" << std::endl;
  std::cout << str5 << std::endl;
  str5.reset();
  std::cout << "Reset " << str5.empty() << std::endl;

  MyString str6;
  str6 = "AAAASASA";
  std::cout << "\nCopy assigment operator with const char* on stack worked."
            << std::endl;

  MyString str7;
  str6 = "AAAASssssssssssssssssssASA";
  std::cout << "\nCopy assigment operator with const char* on heap worked."
            << std::endl;

  std::string strng = "ASASASASASASASASAS";
  MyString str8;
  str8 = strng;
  std::cout << "\nCopy assigment operator with std::string worked."
            << std::endl;

  std::string strng1 = "ASASASAaaaaaaaaaaaaaaaaaaaSASASASASAS";
  MyString str12(strng1);
  std::cout << "\nCopy assigment operator with std::string worked." << std::endl;
  std::cout << str12 << std::endl;

  MyString str9 = std::move(str8);
  std::cout << "\nMove constructor worked." << std::endl;
  std::cout << str8.empty() << std::endl;
  
  MyString str10;
  std::cin >> str10;
  std::cout << "Input " << str10 << std::endl;
}