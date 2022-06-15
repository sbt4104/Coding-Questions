/*
Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number. Find the total sum of all the numbers represented by all paths.
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
    static int sumPathNumbers(TreeNode *root);
    static void sumPathNumbersRecursive(TreeNode *root, int currSum, int &totalSum);
};

int TreeTraversal::sumPathNumbers(TreeNode *root) {
    int totalSum=0;
    sumPathNumbersRecursive(root, 0, totalSum);
    return totalSum;
}

void TreeTraversal::sumPathNumbersRecursive(TreeNode *root, int currSum, int &totalSum){
    if(root==nullptr) {return;}
    
    currSum = currSum*10 + root->data;
    if(root->left==nullptr && root->right==nullptr) {
        totalSum+=currSum;
    }

    sumPathNumbersRecursive(root->left, currSum, totalSum);
    sumPathNumbersRecursive(root->right, currSum, totalSum);
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    cout<<"ans: "<<TreeTraversal::sumPathNumbers(root)<<endl;
    return 0;
}