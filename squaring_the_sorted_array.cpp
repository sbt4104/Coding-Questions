/*
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> input;
        int len;
    public:
        Solution(vector<int> vec): input(vec) {
            len = input.size();
        }
        vector<int> sortSquaredArray();
};

vector<int> Solution::sortSquaredArray() {
    int index=0;
    for(index=0; index<len; index++) {
        if(input[index] >=0 ) {
            break;
        }
    }

    int left=index, right=index+1;
    vector<int> ans;
    while(left>=0 && right<len) {
        int sqleft = pow(input[left],2);
        int sqright = pow(input[right],2);
        if(sqright <= sqleft) {
            ans.push_back(sqright);
            right++;
        } else {
            ans.push_back(sqleft);
            left--;
        }
    }

    left = min(len-1, left);
    while(left>=0) {
        int sqleft = pow(input[left],2);
        ans.push_back(sqleft);
        left--;
    }

    right = max(0,right);
    while(right<len) {
        int sqright = pow(input[right],2);
        ans.push_back(sqright);
        right++;
    }

    return ans;
}

int main() {
    Solution obj({-2, -1, 0, 2, 3});
    vector<int> ans = obj.sortSquaredArray();
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;
    return 0;
}