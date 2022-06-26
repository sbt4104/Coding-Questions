/*
Given a set of distinct numbers, find all of its permutations.
use queue to avoid vector erase step
*/

#include<bits/stdc++.h>
using namespace std;

class Permutations{
    public:
    static vector<vector<int>> getAllPermutations(vector<int> input){
        vector<vector<int>> ans;
        queue<vector<int>> permute;
        permute.push(vector<int> ());
        for(int index=0; index<input.size(); index++) {
            int size=permute.size();
            while(size--) {
                vector<int> prev=permute.front();
                permute.pop();
                for(int indexJ=0; indexJ<=prev.size(); indexJ++) {
                    vector<int> curr(prev);
                    curr.insert(curr.begin() + indexJ, input[index]);
                    curr.size()==input.size() ? ans.push_back(curr): permute.push(curr);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans = Permutations::getAllPermutations({1,2,3});
    for(auto subset: ans) {
        for(auto val: subset) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}