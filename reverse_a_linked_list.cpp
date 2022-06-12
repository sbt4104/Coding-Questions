/*
reverse the linked list ans return the new head
*/
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode(int data) {
            this->data=data;
            next=nullptr;
        }
};

class LinkedList{
    public:
        static ListNode* reverseList(ListNode* head);
        static void printList(ListNode* head) {
            ListNode* curr=head;
            while(curr) {
                cout<<curr->data<<" ";
                curr=curr->next;
            }
            cout<<endl;
        }
};

ListNode* LinkedList::reverseList(ListNode* head) {
    ListNode *next=head, *prev=nullptr, *curr=head;
    while(curr) {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    LinkedList::printList(head);
    ListNode *newHead = LinkedList::reverseList(head);
    LinkedList::printList(newHead);
    return 0;
}