/*
Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
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
    static vector<int> getRightView(TreeNode *root);
};

vector<int> TreeTraversal::getRightView(TreeNode *root) {
    vector<int> rightView;
    if(root == nullptr) {
        return ans;
    }

    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        int size=queue.size();
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();

            if(index==size-1) {
                ans.push_back(curr->data);
            }
            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
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
    root->left->right->left = new TreeNode(80);

    vector<int> ans=TreeTraversal::getRightView(root);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;

    return 0;
}