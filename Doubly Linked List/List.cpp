#include "List.h"

#include <iostream>

DoublyLinkedList::DoublyLinkedList() 
    : m_size {0}
    , m_head {nullptr}
    , m_tail {nullptr} 
{
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other) {
    m_head = new Node();
    Node* tmp = other.m_head->m_next;
    Node* prev = m_head;
    prev->m_value = other.m_head->m_value; 
    while (tmp) {
        Node* temp = new Node();
        temp->m_prev = prev;
        prev->m_next = temp;
        temp->m_value = tmp->m_value;
        prev = temp;
        tmp = tmp->m_next;
    }
    m_tail = prev;
    m_size = other.m_size;
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other) {
    if (this != &other) {
        m_head = new Node();
        Node* tmp = other.m_head->m_next;
        Node* prev = m_head;
        prev->m_value = other.m_head->m_value; 
        while (tmp) {
            Node* temp = new Node();
            temp->m_prev = prev;
            prev->m_next = temp;
            temp->m_value = tmp->m_value;
            prev = temp;
            tmp = tmp->m_next;
        }
        m_tail = prev;
        m_size = other.m_size;
    }
    return *this;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (m_head) {
        Node* tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
}

void DoublyLinkedList::pushFront(const int value) {
    Node* newNode = new Node();
    newNode->m_value = value;
    if(m_head == nullptr) {
        m_head = newNode;
        m_tail = newNode;
    }
    else {
        newNode->m_next = m_head;
        m_head->m_prev = newNode;
        m_head = newNode;
    }
    m_size++;
}

void DoublyLinkedList::pushBack(const int value) {
    Node* newNode = new Node();
    newNode->m_value = value;
    if (m_tail == nullptr) {
        m_head = newNode;
        m_tail = newNode;
    }
    else {
        newNode->m_prev = m_tail;
        m_tail->m_next = newNode;
        m_tail = newNode;
    }
    m_size++;
}

void DoublyLinkedList::insert(const int index, const int value) {
    if (index < 0 || index > m_size){
        throw std::out_of_range("Out of range.");
    }
    if (index == 0) {
        pushFront(value);
    }
    if (index == m_size) {
        pushBack(value);
    }

    Node* newNode = new Node();
    Node* tmp = m_head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->m_next;
    }
    newNode->m_prev = tmp->m_prev;
    newNode->m_next = tmp;
    tmp->m_prev->m_next = newNode;
    tmp->m_prev = newNode;
    newNode->m_value = value;
    m_size++;
}  

void DoublyLinkedList::remove(const int index) {
    if (index < 0 || index > m_size) {
        throw std::out_of_range("Out of range!");
    }
    Node* tmp = m_head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->m_next;
    }
    if (tmp->m_prev) {
        tmp->m_prev->m_next = tmp->m_next;
    }
    else {
        m_head = tmp->m_next;
    }
    if (tmp->m_next) {
        tmp->m_next->m_prev = tmp->m_prev;
    }
    else {
        m_tail = tmp->m_prev;
    }
    delete tmp;
    m_size--;
}

int DoublyLinkedList::get(const int index) const {
    if(index < 0 || index > size()) {
        throw std::out_of_range("Out of range!");
    }
    if (index == 0) {
        return m_head->m_value;
    }
    if (index == size()) {
        return m_tail->m_value;
    }
    Node* tmp = m_head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->m_next;
    }
    return tmp->m_value;
}

int DoublyLinkedList::size() const {
    return m_size;
}

void DoublyLinkedList::printList() const {
    Node* tmp = m_head;
    while (tmp) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::printReverse() const {
    Node* tmp = m_tail;
    while (tmp) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_prev;
    }
    std::cout << std::endl;
}