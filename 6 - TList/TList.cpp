#include <iostream>
#include <list>
using namespace std;

template <class T>


class List {
private :    
    struct Node {
        T value; 
        Node* next;
        Node(T _value) : value(_value), next(nullptr) {}
    };
    
    Node* head;

public :
    List() : head(nullptr) {}  
    List(T _value) {
        Node* p = new Node(_value);
        head = p;
    }

    ~List() { delete head; }   


    bool isEmpty() {
        return head == nullptr;
    }

    void addToHead(T _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            head = p;
            return;
        }
        p->next = head;
        head = p;
    }

    template<std::size_t N> void addToHead(T (&array)[N]) {
        Node* p = new Node(array[0]);
        if (isEmpty())
            head = p;

        for (int i = 1; i < N; i++) {
            Node* p = new Node(array[i]);
            p->next = head;
            head = p;
        }
    }

    void addToTail(T _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            head = p;
            return;
        }
        Node* iter = head;
        while (iter->next != 0) {
            iter = iter->next;
        }
        iter->next = p;
    }

    void print() {
        if (isEmpty())
            return;
        Node* p = head;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(T _value) {
        Node* p = head;
        while (p && p->value != _value)
            p = p->next;
        return (p && p->value == _value) ? p : nullptr;
    }

    void removeFirst() {
        if (isEmpty())
            return;
        Node* p = head;
        head = p->next;
        delete p;
    }

    void removeLast() {
        if (isEmpty())
            return;
        if (head->next == nullptr) {
            removeFirst();
            return;
        }
        Node* p = head;
        while (p->next != nullptr)
            p = p->next;
        delete p->next;
        p->next = nullptr;
    }

    void addAfterNode(Node* elem, T _value) {
        if (elem == NULL) {
            cout << "Element does not exist." << endl;
            return;
        }
        Node* newElem = new Node(_value);
        newElem->next = elem->next;
        elem->next = newElem;
    }

    void del(T _value) {
        if (isEmpty())
            return;
        if (head->value == _value) {
            removeFirst();
            return;
        }
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->value != _value) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "Element does not exist." << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    void delAll() {
        while (head)
            removeFirst();
    }

    Node* operator[] (const int index) {
        if (isEmpty())
            return nullptr;

        Node* p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }

};



int main()
{   
    list<int> l;
    list<int>::iterator iter = l.begin();

    const int n = 5;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n";

    //l.addToHead(a);

    //l.print();

}
