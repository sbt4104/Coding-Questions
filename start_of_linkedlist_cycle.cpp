/*
Given the head of a Singly LinkedList that contains a cycle, write a function to find the starting node of the cycle.
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
        static int cycleLen(ListNode *head);
};

class LinkedListCycleStart{
    public:
        static ListNode* startNode(ListNode *head, int cycLen);
};

int LinkedListCycle::cycleLen(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast!=nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            int count=1;
            while(slow->next != fast) {
                count++;
                slow = slow->next;
            }
            return count;
        }
    }
    return -1;
}

ListNode* LinkedListCycleStart::startNode(ListNode *head, int cycleLen) {
    ListNode *first=head, *second=head;
    for(int index=0; index<cycleLen; index++) {
        second = second->next;
    }

    while(first != second) {
        first=first->next;
        second=second->next;
    }

    return first;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = head->next->next;

    int cycLen=LinkedListCycle::cycleLen(head);
    if(cycLen != -1) {
        cout<<"ans: "<<LinkedListCycleStart::startNode(head, cycLen)->data<<endl;
    }
    return 0;
}