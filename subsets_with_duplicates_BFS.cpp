/*
Given a set of numbers that might contain duplicates, find all of its distinct subsets.
Solution: main idea to push elements only to those elemets that are newly created in the last step
*/
#include<bits/stdc++.h>
using namespace std;

class Subusets{
    public:
    static vector<vector<int>> getAllSubsets(vector<int> input){
        vector<vector<int>> ans;
        sort(input.begin(), input.end());
        ans.push_back(vector<int>());
        int startIndex=0, endIndex=0;
        for(int indexI=0; indexI<input.size(); indexI++) {
            startIndex=0;
            if(indexI > 0 && input[indexI] == input[indexI-1]) {
                startIndex=endIndex+1;
            }
            endIndex=ans.size();
            for(int indexJ=startIndex; indexJ<endIndex; indexJ++) {
                vector<int> curr(ans[indexJ]);
                curr.push_back(input[indexI]);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans = Subusets::getAllSubsets({1,3,3});
    for(auto subset: ans) {
        for(auto val: subset) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}