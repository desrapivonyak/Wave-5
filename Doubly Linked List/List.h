#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class Doubly_linked_list {
public:
    Doubly_linked_list();
    Doubly_linked_list(const Doubly_linked_list&);
    ~Doubly_linked_list();
    Doubly_linked_list& operator=(const Doubly_linked_list&);

public:
    void push_front(const int);
    void push_back(const int);
    void insert(const int, const int);
    void remove(const int);
    int get(const int) const;
    void print_list() const;
    void print_reverse() const;
    int size() const;

private:
    void copy(const Doubly_linked_list&);
    void clear();

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