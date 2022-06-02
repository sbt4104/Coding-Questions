/*
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
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

class PalindromeList{
    public:
    static ListNode *reverse(ListNode *head);
    static bool isPalindrome(ListNode *head);
    static void printList(ListNode *head);
};

void PalindromeList::printList(ListNode *head) {
    while(head) {
        cout<<"print: "<<head->data<<endl;
        head=head->next;
    }
}

ListNode* PalindromeList::reverse(ListNode *head) {
    ListNode *prev=nullptr;
    while(head) {
        ListNode *next=head->next;
        head->next = prev;
        prev=head;
        head=next;
    }
    return prev;
}

bool PalindromeList::isPalindrome(ListNode *head) {
    ListNode *first=head,*second=head, *temp=head;
    while(second!=nullptr && second->next!=nullptr) {
        first=first->next;
        second=second->next->next;
    }

    ListNode* secondHead=reverse(first);
    ListNode* saveSecondHead=secondHead;

    while(head!=nullptr && secondHead!=nullptr) {
        if(head->data != secondHead->data) {
            break;
        }
        head=head->next;
        secondHead=secondHead->next;
    }

    reverse(saveSecondHead);
    if(secondHead==nullptr) return true;
    return false;

}

int main() {
    ListNode *head = new ListNode(10);
    head->next = new ListNode(10);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(10);
    cout<<"ans: "<<PalindromeList::isPalindrome(head)<<endl;
    return 0;
}