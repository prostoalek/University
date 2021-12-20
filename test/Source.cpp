#include <iostream>
using namespace std;

//#include <stdexcept>
//#include "func.h"

// связанный список
template <typename T> class List; // Предварительное объявление, используется для объявления класса друга
template <typename N>
class Iterator {

    N* pos;
    template <typename T> friend class List; // шаблон списка может получить доступ к закрытым членам для вставки и удаления

public:
    // Переименование различных типов для облегчения извлечения других шаблонов
    /*typedef typename N::value_type value_type;
    typedef typename N::reference_type reference_type;
    typedef typename N::const_reference_type const_reference_type;
    typedef Iterator<N> self_type;*/

    // Создаем пустой итератор
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

// Шаблон контейнера двустороннего связанного списка
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
// Шаблон двойного связанного списка
template <typename T>

class List {
    //typedef Node<T> Node<T>;
    Node<T>* head; // Указатель узла головы
public:
    //typedef T value_type;
    //typedef Iterator<Node<T>>iterator;

    List() :head() {}
    ~List() {
        // Удаляем пространство узла связанного списка, когда отмечен галочкой связанный список
        while (head)
        {
            Node<T>* n = head;
            head = head->next;
            delete n;
        }

    }

    // Вставляем данные из заголовка таблицы
    void push_front(T const& v) {
        head = new Node<T>(v, 0, head);
        if (head > next) {
            head->next->prev = head;
        }
    }
    // Удалить данные из заголовка таблицы
    void pop_front(T const& v) {
        if (head) {
            Node<T>* n = head;
            head = head->next;
            head->prev = 0;
            delete n;
        }
    }

    // Вставить данные из указанной позиции
    void insert(iterator it, T const& v) {
        Node<T>* n = it.pos;
        if (n) {
            Node<T>* new_node = new Node<T>(v, n, n->next);
            new_node->next->prev = new_node;
            n->next = new_node;
        }
    }

    // Удалить указанный элемент
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

    // Возвращаемся к итератору, указывающему на головной узел связанного списка
    iterator begin() {
        return iterator(head);
    }
    // Пустой итератор представляет конец связанного списка
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