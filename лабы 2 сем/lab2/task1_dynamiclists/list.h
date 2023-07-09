#ifndef LIST_H
#define LIST_H
#include"bus.h"

struct Node
{
public:
    Bus data;
    Node *prev, *next;
    Node(Bus data)
    {
           this -> data = data;
           this -> prev = this -> next = nullptr;
    }
};

class List
{
public:
    Node *head, *tail;
    List();
   ~List();
    void push_front(Bus);
    void push_back(Bus);
    void pop_front();
    void pop_back();
    Node* getAt(int);
    Node* operator [](int);
    void insert(int, Bus);
    void erase(int);
private:

};

#endif // LIST_H
