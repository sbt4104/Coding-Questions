/*
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode(int val): data(val) {}
};

class LinkedList {
    public:
        void reorder(ListNode *head);
        void printList(ListNode *head);
        ListNode* reverse(ListNode *head);
};

void LinkedList::printList(ListNode *head) {
    ListNode *temp=head;
    while(temp) {
        cout<<"print: "<<temp->data<<endl;
        temp=temp->next;
    }
}

ListNode* LinkedList::reverse(ListNode *head) {
    ListNode *prev=nullptr;
    while(head!=nullptr) {
        ListNode *next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

void LinkedList::reorder(ListNode *head) {
    //find middle node
    ListNode *slow=head, *fast=head, *temp1=head;
    while(fast!=nullptr && fast->next!=nullptr) {
        slow=slow->next;
        fast=fast->next->next;
    }

    //rever list from middle elements onwards
    ListNode *secondHead = reverse(slow);

    //start reordering
    while(secondHead!=nullptr && head!=nullptr) {
        ListNode *temp=head->next;
        head->next=secondHead;
        head=temp;

        temp=secondHead->next;
        secondHead->next=head;
        secondHead=temp;
    }

    head->next=nullptr;
    printList(temp1);
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);    

    LinkedList obj;
    obj.printList(head);
    obj.reorder(head);
    return 0;
}