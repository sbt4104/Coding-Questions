/*
Given a binary tree, connect each node with its level order successor. The last node of each level should point to a null node.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right, *next;
    TreeNode(int data) {
        this->data=data;
        left=right=next=nullptr;
    }
};

class TreeTraversal{
    public:
    static void printList(TreeNode *head);
    static void connectallNodes(TreeNode *);
};

void TreeTraversal::printList(TreeNode *head) {
    TreeNode *curr=head;
    while(curr) {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void TreeTraversal::connectallNodes(TreeNode *root){
    if(root==nullptr) {
        return;
    }

    TreeNode *prev=nullptr;
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()){
        int size=queue.size();
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();
            if(prev!=nullptr) {
                prev->next=curr;
            }
            prev=curr;

            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
    }
}

int main(){
    TreeNode *root= new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);
    root->left->right->left = new TreeNode(80);

    TreeTraversal::connectallNodes(root);
    TreeTraversal::printList(root);
    return 0;
}