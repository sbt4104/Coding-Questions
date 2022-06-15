/*
Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

Note: You can always assume that there are at least two leaf nodes in the given tree.
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
    static int getTreeDiameter(TreeNode *root);
    static int getTreeDiameterRecursive(TreeNode *root, int &globalDiameter);
};

int TreeTraversal::getTreeDiameter(TreeNode *root){
    int ans=0;
    getTreeDiameterRecursive(root, ans);
    return ans;
}

int TreeTraversal::getTreeDiameterRecursive(TreeNode *root, int &globalDiameter){
    if(root==nullptr) {return 0;}
    
    // found a leaf node, height is 1
    if(root->left==nullptr && root->right==nullptr) {
        return 1;
    }

    int heightLeft=getTreeDiameterRecursive(root->left, globalDiameter);
    int heightRight=getTreeDiameterRecursive(root->right, globalDiameter);
    globalDiameter=max(globalDiameter, heightLeft+heightRight+1);
    
    return max(heightLeft, heightRight)+1;
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->right = new TreeNode(10);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(11);
    cout<<"ans: "<<TreeTraversal::getTreeDiameter(root)<<endl;
    return 0;
}