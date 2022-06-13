/*
Given a binary tree, populate an array to represent its level-by-level traversal. You should populate the values of all nodes of each level from left to right in separate sub-arrays.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data) {
        this->data = data;
        left=nullptr;
        right=nullptr;
    }
};

class TreeTraversal{
    public:
    static vector<vector<int>> levelOrderTraversal(TreeNode *root);
};

vector<vector<int>> TreeTraversal::levelOrderTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        vector<int> temp;
        int size = queue.size();
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();
            temp.push_back(curr->data);
            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}


int main() {
    TreeNode *root= new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    vector<vector<int>> ans = TreeTraversal::levelOrderTraversal(root);

    for(int index=0; index<ans.size(); index++) {
        for(int x: ans[index]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}