/*
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.
If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList{
    public:
    static void printList(ListNode *head) {
        ListNode *curr=head;
        while(curr) {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    static ListNode* reverseKSubList(ListNode *head, int k);
};

ListNode* LinkedList::reverseKSubList(ListNode *head, int k) {
    ListNode *curr=head, *newLast=nullptr, *newFirst=nullptr, *next=head, *prev=nullptr;
    int index=1;

    while(true) {    
        index=1;
        newLast=prev;
        newFirst=curr;
        while(index<=k && curr!=nullptr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            index++;
        }
        if(newLast!=nullptr) {
            newLast->next=prev;
        } else {
            head=prev;
        }
        newFirst->next=curr;
        prev=newFirst;
        if(curr==nullptr) {break;}
    }
    return head;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    LinkedList::printList(head);
    ListNode *newHead = LinkedList::reverseKSubList(head,2);
    LinkedList::printList(newHead);
    return 0;
}