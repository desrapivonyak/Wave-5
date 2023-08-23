#include <iostream>
#include "String.hpp"

int main() {
    // Default constructor
    String str1;
    std::cout << "str1: " << str1.c_str() << std::endl;

    // Constructor with size
    String str2(10);
    std::cout << "str2: " << str2.c_str() << std::endl;

    // Constructor with char array
    String str3("Hello, world!");
    std::cout << "str3: " << str3.c_str() << std::endl;

    // Copy constructor
    String str4 = str3;
    std::cout << "str4 (copy): " << str4.c_str() << std::endl;

    // Assignment operator
    String str5;
    str5 = str4;
    std::cout << "str5 (assigned): " << str5.c_str() << std::endl;

    // Size and capacity
    std::cout << "Size of str5: " << str5.size() << std::endl;
    std::cout << "Capacity of str5: " << str5.capacity() << std::endl;

    // Indexing operator
    std::cout << "Character at index 7 in str5: " << str5[7] << std::endl;

    // Modifying the string
    str5[0] = '!';
    std::cout << "Modified str5: " << str5.c_str() << std::endl;

    // Empty check
    if (str1.empty()) {
        std::cout << "str1 is empty." << std::endl;
    } else {
        std::cout << "str1 is not empty." << std::endl;
    }

    // Reserve and shrink_to_fit
    str5.reserve(50);
    std::cout << "str5 after reserving: " << str5.c_str() << std::endl;
    
    str5.shrink_to_fit();
    std::cout << "str5 after shrinking: " << str5.c_str() << std::endl;

    return 0;
}