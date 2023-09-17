#include <iostream>
#include "MyString.hpp"

int main()
{
    MyString str;
    std::cout << str << "Default ctor worked!" << std::endl;

    std::cout << "Something after default" << std::endl;

    // std::cin >> str;
    // std::cout << str << std::endl;

    MyString str1 {"Hello"};
    std::cout << "char* ctor worked" << std::endl;
    std::cout << str1 << std::endl;

    //std::cin >> str1;
    //std::cout << str1 << std::endl;

    // std::string s = "World";
    // std::cout << s << std::endl;
    // MyString str2 {s};
    // str2[2] = 'b';
    // std::cout << str2 << std::endl;

    // MyString str3 {str2};
    // std::cout << str3 << std::endl;

    // MyString str4;
    // str4 += "Hi";
    // std::cout << str4 << std::endl;
    // std::cout << str4.size() << std::endl;
    // str4.reset();
    // std::cout << str4 << std::endl;
}