/*
Given a binary tree, populate an array to represent the averages of all of its levels.
*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(int data){
        this->data=data;
        left=right=nullptr;
    }
};

class TreeTraversal{
    public:
    static vector<float> getLevelAverages(TreeNode *root);
};

vector<float> TreeTraversal::getLevelAverages(TreeNode *root){
    vector<float> ans;
    if(root==nullptr) {return ans;}

    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        int size=queue.size();
        float sum=0;
        for(int index=0; index<size; index++) {
            TreeNode *curr=queue.front();
            queue.pop();
            sum+=curr->data;
            if(curr->left) {
                queue.push(curr->left);
            }
            if(curr->right) {
                queue.push(curr->right);
            }
        }
        ans.push_back(sum/size);
    }
    return ans;
}

int main(){
    TreeNode *root= new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    vector<float> ans=TreeTraversal::getLevelAverages(root);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;
    return 0;
}