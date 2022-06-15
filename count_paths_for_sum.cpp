/*
Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’. Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).
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
    static int countPathsForSum(TreeNode *root, int sum);
    static int countPathsForSumRecursive(TreeNode *root, vector<int> &sequence, int sum);
};

int TreeTraversal::countPathsForSum(TreeNode *root, int sum){
    vector<int> sequence;
    return countPathsForSumRecursive(root, sequence, sum);
}

int TreeTraversal::countPathsForSumRecursive(TreeNode *root, vector<int> &sequence, int sum){
    if(root==nullptr) {return 0;}
    sequence.push_back(root->data);
    int sumTillNow=0, count=0;
    for(int index=sequence.size()-1; index>=0; index--) {
        sumTillNow+=sequence[index];
        if(sumTillNow==sum) {
            count++;
        }
    }

    count += countPathsForSumRecursive(root->left, sequence, sum);
    count += countPathsForSumRecursive(root->right, sequence, sum);

    sequence.pop_back();
    return count;
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout<<"ans: "<<TreeTraversal::countPathsForSum(root, 12)<<endl;
    return 0;
}