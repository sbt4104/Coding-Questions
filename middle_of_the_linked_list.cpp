/*
Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
*/
#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode(int val) {
            data=val;
            next=nullptr;
        }
};

class LinkedListMiddle{
    public:
    static ListNode* getMiddle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    cout<<"ans: "<<LinkedListMiddle::getMiddle(head)->data<<endl;
    return 0;
}