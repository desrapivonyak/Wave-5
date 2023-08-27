#include "List.h"

#include <iostream>

Doubly_linked_list::Doubly_linked_list() 
    : m_size {0}
    , m_head {nullptr}
    , m_tail {nullptr} 
{
}

Doubly_linked_list::Doubly_linked_list(const Doubly_linked_list& other) {
    copy(other);
}

Doubly_linked_list& Doubly_linked_list::operator=(const Doubly_linked_list& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

Doubly_linked_list::~Doubly_linked_list() {
    clear();
}

void Doubly_linked_list::push_front(const int value) {
    Node* new_node = new Node();
    new_node->m_value = value;
    if(m_head == nullptr) {
        m_head = new_node;
        m_tail = new_node;
    } else {
        new_node->m_next = m_head;
        m_head->m_prev = new_node;
        m_head = new_node;
    }
    ++m_size;
}

void Doubly_linked_list::push_back(const int value) {
    Node* new_node = new Node();
    new_node->m_value = value;
    if (m_tail == nullptr) {
        m_head = new_node;
        m_tail = new_node;
    } else {
        new_node->m_prev = m_tail;
        m_tail->m_next = new_node;
        m_tail = new_node;
    }
    ++m_size;
}

void Doubly_linked_list::insert(const int index, const int value) {
    if (index < 0 || index > m_size){
        throw std::out_of_range("Out of range.");
    }

    if (index == 0) {
        push_front(value);
    }

    if (index == m_size) {
        push_back(value);
    } else {
        Node* new_node = new Node();
        Node* tmp = m_head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->m_next;
        }
        new_node->m_prev = tmp->m_prev;
        new_node->m_next = tmp;
        tmp->m_prev->m_next = new_node;
        tmp->m_prev = new_node;
        new_node->m_value = value;
        ++m_size;
    }
}  

void Doubly_linked_list::remove(const int index) {
    if (index < 0 || index > m_size) {
        throw std::out_of_range("Out of range!");
    }

    Node* tmp = m_head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->m_next;
    }

    if (tmp->m_prev) {
        tmp->m_prev->m_next = tmp->m_next;
    } else {
        m_head = tmp->m_next;
    }

    if (tmp->m_next) {
        tmp->m_next->m_prev = tmp->m_prev;
    } else {
        m_tail = tmp->m_prev;
    }

    delete tmp;
    --m_size;
}

int Doubly_linked_list::get(const int index) const {
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

int Doubly_linked_list::size() const {
    return m_size;
}

void Doubly_linked_list::print_list() const {
    Node* tmp = m_head;
    while (tmp) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_next;
    }
    std::cout << std::endl;
}

void Doubly_linked_list::print_reverse() const {
    Node* tmp = m_tail;
    while (tmp) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_prev;
    }
    std::cout << std::endl;
}

void Doubly_linked_list::clear() {
    while (m_head) {
        Node* tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
    m_head = nullptr;
    m_tail = nullptr;
}

void Doubly_linked_list::copy(const Doubly_linked_list& other) {
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