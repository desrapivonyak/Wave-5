#include "List.h"

#include <iostream>

int main() {
    Doubly_linked_list node;
    node.push_back(5);
    node.push_front(15);
    node.push_back(3);
    //node.print_list();
    //node.print_reverse();
    //std::cout << node.size() << std::endl;

    //Doubly_linked_list node1(node);
    //node1.print_list();
    //node1.print_reverse();
    //std::cout << node1.size() << std::endl;

    //Doubly_linked_list node2;
    //node2 = node;
    //node2.print_list();
    //node2.print_reverse();
    //std::cout << node2.size() << std::endl;

    //node2.insert(2, 7);
    //node2.print_list();
    //node2.remove(2);
    //node2.print_list();
    //std::cout << node2.get(1) << std::endl;

    node.traverse([](int x) {return x % 5 == 0;});
}