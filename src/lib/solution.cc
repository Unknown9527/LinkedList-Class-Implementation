#include "solution.h"
#include<iostream>

using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
    head_ = NULL;
}

SinglyLinkedList::SinglyLinkedList(const vector<int> input0, int i) // time complexity Nlog(N)
{
    ListNode *p = new ListNode(0);
    int size = input0.size();
    head_ = p;
    for (int j = 0; j < size-1; j++)
    {   
        ListNode *temp = new ListNode(0);
        p->val = input0[j];
        // ListNode *temp = new ListNode(0);
        p->next = temp;
        p = p->next; 
    }
    p->val = input0[size-1];
    if ( i == -1)
    {
        p->next = nullptr;
    }
    else if (i >= size)
    {
        p->next = nullptr;
    }
    else
    {
        ListNode *temp = head_;
        for(int j = 0; j!=i; j++)
        {
            temp = temp->next;
        }
        p->next = temp;
    }
}

bool SinglyLinkedList::empty() // time complexity O(N)
{
    if(head_->next==NULL)
    {
        return true;
    }    
    else
    {
        return false;
    }
}

int SinglyLinkedList::size() // time complexity O(N)
{
    ListNode *p = head_;
    int size = 0;
    while(p!=NULL){
        size++;
        p = p->next;
    }
    return size;
}

void SinglyLinkedList::push_back(int i) // time complexity O(N)
{
    ListNode *p = new ListNode(0);
    p->val = i;
    p->next = nullptr;
  
    ListNode *cur = head_;              
    if (head_ == NULL) 
    {           
        head_ = p;
    }
    else                          
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = p;
    }
}

void SinglyLinkedList::push_front(int i) // time complexity O(1)
{
    ListNode *p = new ListNode(0);
    p->val = i;
    p->next = head_;
    head_ = p;
}

void SinglyLinkedList::insert_after(ListNode *p, int i) // time complexity O(N)
{
    if(head_ == NULL)
    {                               
        head_ = p; 
        p->val = i;                
        return;                
    }
    ListNode *cur = head_;  
    if(cur->val==p->val){      
        p->val = i;
        head_->next = p;    
        p->next = nullptr;      
        return;
    }
    while(cur->val != p->val)
    {
        cur = cur->next;          
    }
    if(cur->val == p->val)
    {            
        p->next = cur->next;
        p->val = i;
        cur->next = p;
    }
}

void SinglyLinkedList::erase(ListNode* p) // // time complexity O(N)
{
    if(head_ == NULL)
    {
        return;       
    }
    ListNode *cur = head_;                         
    if(cur->val == p->val)
    {
        head_ = head_->next;     
        delete cur;   
        return;
    }
    while(cur->next->val != p->val)
    { 
        cur = cur->next;            
    }
    if((cur->next)->val == p->val){            
        ListNode *delete_node = cur->next;     
        cur->next = (cur->next)->next;
        delete delete_node;      
    }
 
}

void SinglyLinkedList::pop_front() // time complexity O(N)
{
    if(head_==NULL)
    {
        return;       
    }
    head_->val = (head_->next)->val;
    head_->next = (head_->next)->next;

}

void SinglyLinkedList::pop_back() // time complexity O(N)
{
    if(head_==NULL)
    {
        return;       
    }
    ListNode *cur = head_;                         
    while((cur->next)->next != NULL)
    { 
        cur = cur->next;            
    }
    if(cur->next->next == NULL)
    {                
        cur->next = NULL;     
    }    
}

int SinglyLinkedList::back() // time complexity O(N)
{
    if(head_==NULL)
    {                                              
        return 0;                
    }
    ListNode *p = head_;
    while(p->next != NULL)
    {
        p = p->next;
    }

    return p->val;

}

int SinglyLinkedList::front() // time complexity O(1)
{
    return head_->val;
}
ListNode* SinglyLinkedList::GetBackPointer()
{
    if(head_ == NULL)
    {
        return head_;       
    }
    ListNode *cur = head_;                         
    while(cur->next != NULL)
    { 
        cur = cur->next;            
    }
    if(cur->next == NULL){                
        return cur;     
    }    

}
ListNode* SinglyLinkedList::GetIthPointer(int i) // time complexity O(N)
{
    if(head_ == NULL)
    {
        return head_;       
    }
    ListNode *cur = head_; 
    int n = 0;                        
    while(n!=i-1){ 
        cur = cur->next;
        n++;            
    }              
    return cur;     
  
}

void SinglyLinkedList::print() // time complexity O(N)
{
    if(head_ == NULL)
    {
        return;       
    }
    ListNode *cur = head_;                         
    while(cur->next != NULL)
    { 
        cout << cur->val << " " ; 
        cur = cur->next;
    }
    if(cur->next == NULL)
    {            
        cout << cur->val << " " << endl;    
    }
}

//// void createnode(int value)
//// {
////     ListNode *head, *tail;
////     ListNode *temp = new ListNode()();
////     temp->val = value;
////     temp->next = NULL;
//
////     if (head == NULL)
////     {
////         head = temp;
////         tail = temp;
////         temp = NULL;
////     }else
////     {
////         tail->next = temp;
////         tail = temp;
////     }
//// }
//
//// void display()
//// {
////     ListNode *head, *tail;
////     ListNode *temp = new ListNode()();
////     temp = head;
////     while (temp != NULL)
////     {
////         cout << temp->val << "\t";
////         temp = temp->next;
////     }
//
//// }
//
//int SinglyLinkedList::size() // return size
//{
//    return size_;
//}
//
//void SinglyLinkedList::push_back(int i) // inserts at the back
//{
//    ListNode * temp = new ListNode();
//    temp->val = i;
//    temp->next = tail_;
//    tail_ = temp;
//}
//
//void SinglyLinkedList::push_front(int i) // inserts at the front
//{
//    ListNode * temp = new ListNode();
//    temp->val = i;
//    temp->next = head_;
//    head_ = temp;
//}
//
//void SinglyLinkedList::insert_after(ListNode* p, int i) // inserts value i after p
//{
//    ListNode *next = new ListNode();
//    ListNode *cur = new ListNode();
//    ListNode *temp = new ListNode();
//
//    cur = head_;
//
//    // end condition: current = p;
//    while(cur != p){
//        cur = cur->next;
//    }
//
//    next = cur->next;
//    temp->val = i;
//    cur->next = temp;
//    temp->next = next;
//}
//
//void SinglyLinkedList::erase(ListNode* p) // erase node p
//{
//    ListNode *cur = new ListNode();
//    ListNode *pre = new ListNode();
//    cur = head_;
//
//    while(pre->next!=p){
//        pre = pre->next;
//    }
//
//    // pre->next = p
//    pre->next = (pre->next)->next;
//
//    delete p;
//}
//
//void SinglyLinkedList::pop_front() // removes the first item
//{
//    ListNode *temp = new ListNode();
//    temp = head_;
//    head_ = temp->next;
//    delete temp;
//}
//
//void SinglyLinkedList::pop_back() // removes the last item
//{
//    ListNode *cur = new ListNode();
//    ListNode *pre = new ListNode();
//    ListNode *tail = new ListNode();
//    cur = head_;
//    while (cur->next != NULL)
//    {
//        pre = cur;
//        cur = cur->next;
//    }
//    tail = pre;
//    pre->next = NULL;
//    delete cur;
//
//    // ListNode * temp = new ListNode();
//    // while(pre->next->next != NULL){
//    //     pre = pre->next;
//    // }
//
//    // // Now, pre is the node linked to the last node
//    // temp = pre->next;
//    // pre->next = NULL;
//
//    // delete temp;
//
//}
//
//int SinglyLinkedList::back() // returns the value of last item
//{
//    return tail_->val;
//}
//
//int SinglyLinkedList::front() // returns the value of first item
//{
//    return head_->val;
//}
//
//ListNode * SinglyLinkedList::GetBackPointer() // Return pointer to last item
//{
//    return tail_;
//}
//
//ListNode * SinglyLinkedList::GetIthPointer(int i) // Returns pointer to i(th) element
//{
//    ListNode * temp = new ListNode();
//    temp = head_;
//    // assume the problem means to name the head of the list as "First element" rather than "Zeroth element"
//    for(int c =1; c<i; c++){
//        temp = temp->next;
//    }
//    return temp;
//}
//
//
//// print the list: Empty list: {}. List with items: {1, 2, 3}
//void SinglyLinkedList::print()
//{
//    ListNode * cur = head_;
//    cout << "{";
//    while(cur!=tail_){
//        cout << cur->val << ", ";
//    }
//    // now, cur is the tail, display the value and end with }.
//    cout << cur->val << "}";
//    cout << endl;
//}
