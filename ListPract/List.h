#ifndef List_h
#define List_h
#pragma once
#include<stdio.h>
#include <string>
#endif // !List_h



class List {
public:   
    struct Node {
        std::string value;
        Node* next;
        Node(std::string _value) : value(_value), next(nullptr) {}
    };

    Node* head;

    List() : head(nullptr) {}
    List(std::string _value) {
        Node* p = new Node(_value);
        head = p;
    }

    ~List() { delete head; }

    bool isEmpty();
    void addToHead(std::string _value);
    template<size_t N> void addToHead(std::string(&array)[N]);
    void addToTail(std::string _value);
    void addAfterNode(Node* elem, std::string _value);
    void print();
    Node* find(std::string _value);
    void delFromHead();
    void delFromTail();
    void del(std::string _value);
    void del(Node* ptr);
    void delAll();
    Node* operator[] (const int index);
    Node* FindMin();
};
