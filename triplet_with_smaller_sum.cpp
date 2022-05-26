/*
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        vector<int> input;
        int len, targetSum;
    public:
        Solution(vector<int> vec, int tar): input(vec), targetSum(tar) {
            len = input.size();
        }
        int getCurrPairs(int,int);
        void countTriplets();
};

int Solution::getCurrPairs(int currEle, int index) {
    int left=index, right=len-1, currCount=0;
    while(left<right) {
        int currSum = currEle+input[left]+input[right];
        if(currSum < targetSum) {
            currCount+= right-left;
            left++;
        } else {
            right--;
        }
    }
    return currCount;
}

void Solution::countTriplets() {
    int ans=0;
    sort(input.begin(), input.end());
    for(int index=0; index<len-2; index++) {
        ans += getCurrPairs(input[index], index+1);
    }
    cout<<"ans: "<<ans<<endl;
}

int main() {
    Solution obj({-1, 0, 2, 3},3);
    obj.countTriplets();
    return 0;
}