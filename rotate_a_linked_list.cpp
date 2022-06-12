/*
Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.
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
    static ListNode* rotateList(ListNode *head, int k);
};

ListNode* LinkedList::rotateList(ListNode *head, int k) {
    // find length of list
    ListNode *curr=head, *prev=nullptr, *last=head;
    int len=0;
    while(curr){
        curr=curr->next;
        len++;
    }

    //find the breaking point
    int pos = len - (k%len);
    if(pos==len) {return head;}
    curr=head;
    while(pos-- && curr!=nullptr) {
        prev=curr;
        curr=curr->next;
    }

    if(curr) {
        while(curr->next) {
            curr=curr->next;
        }
        last=curr;
    } else {
        last=prev;
    }

    curr=prev->next;
    last->next = head;
    head=curr;
    prev->next=nullptr;
    return head;
}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next->next = new ListNode(70);
    LinkedList::printList(head);
    ListNode *newHead = LinkedList::rotateList(head,7);
    LinkedList::printList(newHead);
    return 0;
}