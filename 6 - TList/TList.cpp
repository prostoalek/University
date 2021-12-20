#include <iostream>

using namespace std;

template <class T>

class List {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(T _value) : value(_value), next(nullptr), prev(nullptr) {}
    };

    Node* Head;
    Node* Tail;
    Iterator* head;
    Iterator* tail;
    size_t size;

public:
    class Iterator;

    List() : Head(nullptr), Tail(nullptr), size(0) {}
    List(T _value) {
        Node* p = new Node(_value);
        Head = p;
        Tail = p;
        size = 1;
    }

    ~List() { delete[] Head; delete[] Tail }  

    Iterator begin() { 
        return Head; 
    }

    Iterator end() { 
        return Tail; 
    }

    Iterator begin() const {
        return Head;
    }

    Iterator end() const {
        return Tail;
    }


    bool isEmpty() {
        return Head == Tail;
    }

    void insert(Iterator iter, const T& value) {
        Node* el = iter.elem;
        if (iter == --end())
            addToTail(value);
        else {
            Node* nextelem = iter.elen->next;
            Node* p = new Node(value);
            p->next = nextelem;
            p->prev - el;
            nextelem = p;
            el->next = p;
        }
        size++;
    }

    void erase(Iterator iter) {
        Node* el = iter.elem;
        if (iter.begin())
            removeFirst();
        else {
            Node* prevelem = iter.elem->prev;
            Node* nextelem = iter.elem->next;
            prevelem->next = nextelem;
            nextelem->prev = prevelem;
            delete el;
        }
        size--;
    }

    void addToHead(T _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            Head = p;
            Tail = p;
            return;
        }
        p->next = Head;
        Head = p;
        Tail = nullptr;
        size++;
    }

    template<std::size_t N> void addToHead(T (&array)[N]) {
        Node* p = new Node(array[0]);
        if (isEmpty())
            Head = p;

        for (int i = 1; i < N; i++) {
            Node* p = new Node(array[i]);
            p->next = Head;
            Head = p;
        }
    }

    void addToTail(T _value) {
        Node* p = new Node(_value);
        if (isEmpty()) {
            Head = p;
            Tail = p;
            return;
        }
        /*Node* iter = Head;
        while (iter->next != 0) {
            iter = iter->next;
        }
        iter->next = p;*/
        Tail->next = p;
        size++;
    }

    void print() {
        if (isEmpty())
            return;
        Node* p = Head;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(T _value) {
        Node* p = Head;
        while (p && p->value != _value)
            p = p->next;
        return (p && p->value == _value) ? p : nullptr;
    }

    void removeFirst() {
        if (isEmpty())
            return;
        Node* p = Head;
        Head = p->next;
        delete p;
        size--;
    }

    void removeLast() {
        if (isEmpty())
            return;
        if (Head->next == nullptr) {
            removeFirst();
            return;
        }

        Node* p = Head;
        while (p->next != nullptr)
            p = p->next;
        delete p->next;
        p->next = nullptr;
        size--;
    }

    void addAfterNode(Node* elem, T _value) {
        if (elem == NULL) {
            cout << "Element does not exist." << endl;
            return;
        }
        Node* newElem = new Node(_value);
        newElem->next = elem->next;
        elem->next = newElem;
        size++;
    }

    void del(T _value) {
        if (isEmpty())
            return;
        if (Head->value == _value) {
            removeFirst();
            return;
        }
        Node* slow = Head;
        Node* fast = Head->next;
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
        size--;
    }

    void delAll() {
        while (Head)
            removeFirst();
        size = 0;
    }

    Node* operator[] (const int index) {
        if (isEmpty())
            return nullptr;

        Node* p = Head;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }



    class Iterator {
        friend class List<T>;
    private:
        Node* elem;

    public:
        Iterator() : elem(0) {}
        Iterator(Node* el) : elem(el) {}
        Iterator(const Iterator& iter) : elem(iter.elem) {}

        Iterator operator++(int) {
            if (elem != 0)
                elem = elem->next;
            return *this;
        }

        Iterator operator--(int) {
            if (elem != 0)
                elem = elem->prev;
            return *this;
        }

        T& operator*() const {
            return elem->value;
        }

        bool operator==(const Iterator& iter) {
            return elem == iter.elem;
        }

        bool operator!=(const Iterator& iter) {
            return !(*this == iter);
        }

        Iterator& operator+(size_t n)
        {
            for (int i = 0; i < n; i++)
                elem = elem->next;
            return *this;
        }
    };
};



int main()
{   
    List<int> l;
    

    const int n = 5;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n";

    l.addToHead(a);
    List<int>::Iterator iter1 = l.begin();
    List<int>::Iterator iter2 = l.end();

    while(iter1 != iter2)
    {
        std::cout << *iter1 << "\n";
        iter1++;
    }

    //l.print();

}
