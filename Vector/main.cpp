#include "Vector.h"
#include <iostream>

int main()
{
    Vector v1;
    v1.push_back(5);
    std::cout << v1[0] << std::endl;

    Vector v2(5);
    std::cout << v2[2] << std::endl;
    v2[2] = 10;
    std::cout << v2[2] << std::endl;   

    Vector v3(v2);
    std::cout << v3[2] << std::endl;
    std::cout << v3.get_size() << std::endl;
    v3.pop_back();
    std::cout << v3.get_size() << std::endl;;
}