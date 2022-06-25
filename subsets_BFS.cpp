/*
Given a set with distinct elements, find all of its distinct subsets.
*/

#include<bits/stdc++.h>
using namespace std;

class Subusets{
    public:
    static vector<vector<int>> getAllSubsets(vector<int> input) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for(int indexI=0; indexI<input.size(); indexI++) {
            int size = ans.size();
            for(int indexJ=0; indexJ<size; indexJ++) {
                vector<int> curr(ans[indexJ]);
                curr.push_back(input[indexI]);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans = Subusets::getAllSubsets({1,5,3});
    for(auto subset: ans) {
        for(auto val: subset) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}