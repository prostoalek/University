#include<iostream>
#include "List.h"

bool List::isEmpty() {
    return head == nullptr;
}

void List::addToHead(std::string _value) {
    Node* p = new Node(_value);
    if (isEmpty()) {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}

template<std::size_t N > void List::addToHead(std::string(&array)[N]) {
    Node* p = new Node(array[0]);
    if (isEmpty())
        head = p;

    for (int i = 1; i < N; i++) {
        Node* p = new Node(array[i]);
        p->next = head;
        head = p;
    }
}

void List::addToTail(std::string _value) {
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

void List::addAfterNode(Node* elem, std::string _value) {
    if (!elem) {
        std::cout << "Element does not exist." << std::endl;
        return;
    }
    Node* newElem = new Node(_value);
    newElem->next = elem->next;
    elem->next = newElem;
}

void List::print() {
    if (isEmpty())
        return;
    Node* p = head;
    while (p) {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

List::Node* List::find(std::string _value) {
    Node* p = head;
    while (p && p->value != _value)
        p = p->next;
    return (p && p->value == _value) ? p : nullptr;
}

void List::delFromHead() {
    if (isEmpty())
        return;
    Node* p = head;
    head = p->next;
    delete p;
}
         
void List::delFromTail() {
    if (isEmpty())
        return;
    if (head->next == nullptr) {
        delFromHead();
        return;
    }
    Node* p = head;
    while (p->next != nullptr)
        p = p->next;
    delete p->next;
    p->next = nullptr;
}
         
void List::del(std::string _value) {
    if (isEmpty())
        return;
    if (head->value == _value) {
        delFromHead();
        return;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->value != _value) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        std::cout << "Element does not exist." << std::endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}
         
void List::del(List::Node* ptr) {
    if (isEmpty())
        return;
    if (ptr == head) {
        delFromHead();
        return;
    }

    Node* previous = head;
    while (previous && previous->next != ptr)
        previous = previous->next;

    if (!previous) {
        std::cout << "Element does not exist." << std::endl;
        return;
    }
    previous->next = ptr->next;
    delete ptr;
}
         
void List::delAll() {
    while (head)
        delFromHead();
}

List::Node* List::operator[] (const int index) {
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

