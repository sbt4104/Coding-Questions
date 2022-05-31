/*
Given the head of a LinkedList with a cycle, find the length of the cycle.
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

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = head->next;
    cout<<"ans: "<<LinkedListCycle::cycleLen(head)<<endl;
    return 0;
}