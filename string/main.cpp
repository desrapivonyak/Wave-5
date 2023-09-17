#include <iostream>
#include "String.hpp"
// class my_string
// {
// public:
//     my_string(const char* s)
//     {
//         int length = strlen(s);
//         if (length <= 16) {
//             string.onstack[length] = '\0';
//             memcpy(string.onstack, s, length);
//         } else {
//             dyn_str.size = length;
//             dyn_str.ptr = new char[length + 1];
//             strcpy(dyn_str.ptr, s);
//         }
//     }

//     ~my_string()
//     {
//         if (dyn_str.ptr) {
//             delete[] dyn_str.ptr;
//         }
//     }

//     const char* c_str() const
//     {
//         return (dyn_str.ptr) ? dyn_str.ptr : string.onstack;
//     }

// private:
//     struct { int size; char* ptr; } dyn_str;
//     union {
//         char onstack[16];
//         decltype(dyn_str) str;
//     } string;
// };

int main()
{
    String str1("Hello");
    String str2("abcdefghijklmnopqrstuvwxyz");
    std::cout << "str1: " << str1.c_str() << std::endl;
    std::cout << "str2: " << str2.c_str() << std::endl;

    return 0;
}

// int main() {
//     String str1;
//     std::cout << "str1: size=" << str1.size() << ", capacity=" << str1.capacity() << ", empty=" << str1.empty() << std::endl;
    
//     String str2(10);
//     std::cout << "str2: size=" << str2.size() << ", capacity=" << str2.capacity() << ", empty=" << str2.empty() << std::endl;
    
//     String str3("Hello, World!");
//     std::cout << "str3: size=" << str3.size() << ", capacity=" << str3.capacity() << ", empty=" << str3.empty() << ", c_str=" << str3.c_str() << std::endl;
    
//     String str4 = str3;
//     std::cout << "str4: size=" << str4.size() << ", capacity=" << str4.capacity() << ", c_str=" << str4.c_str() << std::endl;
    
//     String str5;
//     str5 = str4;
//     std::cout << "str5: size=" << str5.size() << ", capacity=" << str5.capacity() << ", c_str=" << str5.c_str() << std::endl;
    
//     str5[7] = '-';
//     std::cout << "str5 after modification: c_str=" << str5.c_str() << std::endl;
    
//     str5.reserve(20);
//     std::cout << "str5 after reserve: size=" << str5.size() << ", capacity=" << str5.capacity() << std::endl;
    
//     str5.shrink_to_fit();
//     std::cout << "str5 after shrink_to_fit: size=" << str5.size() << ", capacity=" << str5.capacity() << std::endl;
    
//     String str6("Test");
//     str6 = "NewTest";
//     std::cout << "str6 after assignment: c_str=" << str6.c_str() << std::endl;

//     std::cout << "All tests passed!" << std::endl;
    
//     return 0;
// }