/*
Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
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
    static ListNode* reverseSubList(ListNode *head, int p, int q);
};

ListNode* LinkedList::reverseSubList(ListNode *head, int p, int q) {
    ListNode *curr=head, *newLast=nullptr, *newFirst=nullptr, *next=head, *prev=nullptr;
    int index=1;
    while(index<p) {
        prev=curr;
        curr=curr->next;
        index++;
    }

    newLast=prev;
    newFirst=curr;
    while(index<=q && curr!=nullptr) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        index++;
    }

    //join this sublist to the main list
    if(newLast!=nullptr) {
        newLast->next=prev;
    } else {
        head=prev;
    }
    newFirst->next=curr;
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
    ListNode *newHead = LinkedList::reverseSubList(head, 5,6);
    LinkedList::printList(newHead);
    return 0;
}