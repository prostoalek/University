#include <iostream>
using namespace std;

//#include <stdexcept>
//#include "func.h"

// ��������� ������
template <typename T> class List; // ��������������� ����������, ������������ ��� ���������� ������ �����
template <typename N>
class Iterator {

    N* pos;
    template <typename T> friend class List; // ������ ������ ����� �������� ������ � �������� ������ ��� ������� � ��������

public:
    // �������������� ��������� ����� ��� ���������� ���������� ������ ��������
    /*typedef typename N::value_type value_type;
    typedef typename N::reference_type reference_type;
    typedef typename N::const_reference_type const_reference_type;
    typedef Iterator<N> self_type;*/

    // ������� ������ ��������
    Iterator() :pos(0) {}
    Iterator(N* pos) : pos(pos) {}

    bool operator !=(self_type const& right)const {
        return pos != right.pos;
    }

    bool operator ==(self_type const& right)const {
        return pos != right.pos;
    }

    self_type& operator++() {
        if (pos) pos = pos->next;
        return *this;
    }
    /*reference_type operator*()throw (std::runtime_error) {
        if (pos) return pos->value;
            else 
            throw (std::runtime_error("dereferencing null iterator"));
    }*/

};

// ������ ���������� ������������� ���������� ������
template <typename T>
struct Node {
    /*typedef T value_type;
    typedef T& reference_type;
    typedef const T& const_reference_type;*/

    T value;
    Node* prev;
    Node* next;
    Node(T const& value, Node* prev, Node* next) :value(value), prev(prev), next(next) {}
};
// ������ �������� ���������� ������
template <typename T>

class List {
    //typedef Node<T> Node<T>;
    Node<T>* head; // ��������� ���� ������
public:
    //typedef T value_type;
    //typedef Iterator<Node<T>>iterator;

    List() :head() {}
    ~List() {
        // ������� ������������ ���� ���������� ������, ����� ������� �������� ��������� ������
        while (head)
        {
            Node<T>* n = head;
            head = head->next;
            delete n;
        }

    }

    // ��������� ������ �� ��������� �������
    void push_front(T const& v) {
        head = new Node<T>(v, 0, head);
        if (head > next) {
            head->next->prev = head;
        }
    }
    // ������� ������ �� ��������� �������
    void pop_front(T const& v) {
        if (head) {
            Node<T>* n = head;
            head = head->next;
            head->prev = 0;
            delete n;
        }
    }

    // �������� ������ �� ��������� �������
    void insert(iterator it, T const& v) {
        Node<T>* n = it.pos;
        if (n) {
            Node<T>* new_node = new Node<T>(v, n, n->next);
            new_node->next->prev = new_node;
            n->next = new_node;
        }
    }

    // ������� ��������� �������
    void erase(iterator& it) {
        Node<T>* n = it.pos;
        ++it;
        if (n) {
            if (n->next)n->next->prev = n->prev;
            if (n->prev) n->prev->next = n->next;
            if (head == n) {
                head = n->next;
            }
            delete n;
        }
    }

    bool is_empty()const { return head == 0; }

    // ������������ � ���������, ������������ �� �������� ���� ���������� ������
    iterator begin() {
        return iterator(head);
    }
    // ������ �������� ������������ ����� ���������� ������
    iterator end() {
        return iterator();
    }

};

int main()
{
    List<int> l;


    const int n = 5;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n";

    //l.addToHead(a);
    List<int>::Iterator iter1 = l.begin();
    List<int>::Iterator iter2 = l.end();

    while (iter1 != iter2)
    {
        std::cout << *iter1 << "\n";
        iter1++;
    }

    //l.print();

}