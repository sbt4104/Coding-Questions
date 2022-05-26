/*
Given an array with positive numbers and a target number, find all of its contiguous subarrays whose product is less than the target number.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> input;
        int len, targetProd;
    public:
        Solution(vector<int> vec, int tar): input(vec), targetProd(tar) {
            len = input.size();
        }
        int getSubarrays();
};

int Solution::getSubarrays() {
    int first=0, second=0, ans=0, prod=1;
    for(first=0; first<len; first++) {
        prod = input[first];
        second=first+1;
        while(prod < targetProd && second<len+1) {
            for(int index=first; index<second; index++) {
                cout<<input[index]<<" ";
            }
            cout<<endl;
            prod = prod*input[second];
            second++;
            ans++;
        }   
    }
    return ans;
}

int main() {
    Solution obj({8, 2, 6, 5}, 50);
    cout<<"ans: "<<obj.getSubarrays()<<endl;
    return 0;
}