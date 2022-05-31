/*
Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode(int data) {
            this->data = data;
            next=nullptr;
        }    
};

class LinkedListCycle{
    public:
        static bool hasCycle(ListNode *head);
};

 bool LinkedListCycle::hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast!=nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = head->next->next;
    cout<<"ans: "<<LinkedListCycle::hasCycle(head)<<endl;
    return 0;
}