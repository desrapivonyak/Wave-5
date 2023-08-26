#include "List.h"

#include <iostream>

int main() {
    DoublyLinkedList node;
    node.pushBack(5);
    node.pushFront(15);
    node.pushBack(3);
    node.printList();
    node.printReverse();
    std::cout << "Default ctor: " << node.size() << std::endl;

    DoublyLinkedList node1(node);
    node1.printList();
    node1.printReverse();
    std::cout << "Copy ctor: " << node1.size() << std::endl;

    DoublyLinkedList node2;
    node2 = node;
    node2.printList();
    node2.printReverse();
    std::cout << "Copy assigment operator: " << node2.size() << std::endl;

    node2.insert(2, 7);
    node2.printList();
    node2.remove(2);
    node2.printList();
    std::cout << node2.get(1) << std::endl;
}