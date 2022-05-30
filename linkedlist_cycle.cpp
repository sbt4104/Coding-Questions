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
        bool hasCycle(ListNode *head);
};

bool LinkedListCycle::hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast!=nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return 0;
        }
    }
    return false;
}

int main() {
    return 0;
}