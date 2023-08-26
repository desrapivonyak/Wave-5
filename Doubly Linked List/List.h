#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&);
    ~DoublyLinkedList();
    DoublyLinkedList& operator=(const DoublyLinkedList&);

public:
    void pushFront(const int);
    void pushBack(const int);
    void insert(const int, const int);
    void remove(const int);
    int get(const int) const;
    void printList() const;
    void printReverse() const;
    int size() const;

private:
    struct Node {
        int m_value;
        Node* m_prev;
        Node* m_next;
    };
    Node* m_head;
    Node* m_tail;
    int m_size;
};

#endif