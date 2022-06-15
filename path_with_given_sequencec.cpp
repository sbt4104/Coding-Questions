/*
Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
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
    static bool checkIfSeqPresent(TreeNode *root, vector<int> sequence);
    static bool checkIfSeqPresentrecursive(TreeNode *root, vector<int> sequence, int currIndex);
};

bool TreeTraversal::checkIfSeqPresent(TreeNode *root, vector<int> sequence){
    return checkIfSeqPresentrecursive(root, sequence, 0);
}

bool TreeTraversal::checkIfSeqPresentrecursive(TreeNode *root, vector<int> sequence, int currIndex){
    if(root==nullptr) {return false;}
    
    if(sequence[currIndex]==root->data) {
        return currIndex== sequence.size()-1 ? true : checkIfSeqPresentrecursive(root->left, sequence, currIndex+1) || checkIfSeqPresentrecursive(root->right, sequence, currIndex+1);
    }
    return false;
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(9);
    vector<int> sequence={1,7,2,3,4};
    cout<<"ans: "<<TreeTraversal::checkIfSeqPresent(root, sequence)<<endl;
    return 0;
}