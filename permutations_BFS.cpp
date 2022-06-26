/*
Given a set of distinct numbers, find all of its permutations.
*/

#include<bits/stdc++.h>
using namespace std;

class Permutations{
    public:
    static vector<vector<int>> getAllPermutations(vector<int> input){
        vector<vector<int>> ans;
        ans.push_back(vector<int> ());
        for(int index=0; index<input.size(); index++) {
            int size=ans.size();
            while(size--) {
                for(int indexJ=0; indexJ<=ans[0].size(); indexJ++) {
                    vector<int> curr(ans[0]);
                    curr.insert(curr.begin() + indexJ, input[index]);
                    ans.push_back(curr);
                }
                ans.erase(ans.begin());
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> ans = Permutations::getAllPermutations({1,2,3,4});
    for(auto subset: ans) {
        for(auto val: subset) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}