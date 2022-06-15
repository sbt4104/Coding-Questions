/*
Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum. A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root.
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
    static int pathWithMaxSum(TreeNode *root);
    static int pathWithMaxSumRecursive(TreeNode *root, int &maxSum);
};

int TreeTraversal::pathWithMaxSum(TreeNode *root){
    int maxSum=0;
    pathWithMaxSumRecursive(root, maxSum);
    return maxSum;
}

int TreeTraversal::pathWithMaxSumRecursive(TreeNode *root, int &maxSum){
    if(root==nullptr) {return 0;}

    int leftMax=pathWithMaxSumRecursive(root->left, maxSum);
    int rightMax=pathWithMaxSumRecursive(root->right, maxSum);
    maxSum = max(maxSum, leftMax+rightMax+root->data);

    return max(leftMax, rightMax) + root->data;
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(9);
    cout<<"ans: "<<TreeTraversal::pathWithMaxSum(root)<<endl;
    return 0;
}