/*
Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) {
        this->data=data;
        left=right=nullptr;
    }
};

class TreeTraversal{
    public:
    static int getsuccessor(TreeNode *root, int node);
};

int TreeTraversal::getsuccessor(TreeNode *root, int node) {
    bool found=false;
    if(root==nullptr) return -1;
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        int size=queue.size();
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();
            if(found) return curr->data;

            if(curr->data == node) {
                found=true;
            }

            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
    }

    return INT_MAX;
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

    cout<<"successor: "<<TreeTraversal::getsuccessor(root,40)<<endl;
    return 0;
}