/*
Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.
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
    static bool isPathAvail(TreeNode *root, int sum);
};

bool TreeTraversal::isPathAvail(TreeNode *root, int sum) {

    if(root==nullptr) {
        return false;
    }

    if(root->data==sum && root->left==nullptr && root->right==nullptr) {
        return true;
    }

    return isPathAvail(root->left, sum - root->data) || isPathAvail(root->right, sum - root->data);
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

    cout<<"ans: "<<TreeTraversal::isPathAvail(root, 70)<<endl;
    return 0;
}