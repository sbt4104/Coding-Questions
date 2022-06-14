/*
Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.
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
    static int minDepth(TreeNode *root);
};

int TreeTraversal::minDepth(TreeNode *root) {
    int depth=0;
    if(root==nullptr) return depth;
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        int size=queue.size();
        depth++;
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();

            if(curr->left==nullptr && curr->right==nullptr) {
                return depth;
            }

            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
    }
    return depth;
}


int main() {
    TreeNode *root= new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    //root->right->left = new TreeNode(60);
    //root->right->right = new TreeNode(70);
    root->left->right->left = new TreeNode(80);

    cout<<"min depth: "<<TreeTraversal::minDepth(root)<<endl;
    return 0;
}