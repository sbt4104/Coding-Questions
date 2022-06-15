/*
Given a binary tree and a number ‘S’, find all paths from root-to-leaf such that the sum of all the node values of each path equals ‘S’.
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
    static vector<vector<int>> findPaths(TreeNode *root, int sum);
    static void findPathRecursive(TreeNode *root, int sum, vector<int> currPath, vector<vector<int>> &allPaths);
};

vector<vector<int>> TreeTraversal::findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> currPath;
    findPathRecursive(root, sum, currPath, allPaths);
    return allPaths;
}

void TreeTraversal::findPathRecursive(TreeNode *root, int sum, vector<int> currPath, vector<vector<int>> &allPaths) {
    if(root==nullptr) {return;}
    currPath.push_back(root->data);
    if(root->data == sum && root->left==nullptr && root->right==nullptr) {
        allPaths.push_back(currPath);
        return;
    }

    findPathRecursive(root->left, sum - root->data, currPath, allPaths);
    findPathRecursive(root->right, sum - root->data, currPath, allPaths);
}

int main() {
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans=TreeTraversal::findPaths(root, 12);
    for(auto paths: ans) {
        for(auto path: paths) {
            cout<<path<<" ";
        }
        cout<<endl;
    }
    return 0;
}