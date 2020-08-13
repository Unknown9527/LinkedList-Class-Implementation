#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {};
};

class SinglyLinkedList
{
public:
    SinglyLinkedList();
    SinglyLinkedList(const vector<int>, int);

    ~SinglyLinkedList(){};

    bool empty();
    int size();

    void push_back(int i);
    void push_front(int i);

    void insert_after(ListNode* p, int i);

    void erase(ListNode* p);

    void pop_front();
    void pop_back();

    int back();
    int front();

    ListNode* GetBackPointer();
    ListNode* GetIthPointer(int i);  

    void print();

    ListNode * head_;
    ListNode * tail_;
private:
    int size_;

};

#endif