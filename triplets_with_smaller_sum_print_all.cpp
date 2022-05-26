/*
Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to print all of such triplets.
*/
#include<bits/stdc++.h>
using namespace std;

class Triplets{
    private:
        int first, second, third;
    public:
        Triplets(int t1, int t2, int t3): first(t1), second(t2), third(t3) {}
        void show() {cout<<first<<" "<<second<<" "<<third<<endl;}
};

class Solution{
    private:
        vector<int> input;
        int len, targetSum;
        vector<Triplets> trip;
    public:
        Solution(vector<int> vec, int tar): input(vec), targetSum(tar) {
            len = input.size();
        }
        int getCurrPairs(int,int);
        void countTriplets();
};

int Solution::getCurrPairs(int currEle, int index) {
    int left=index, right=len-1, countall=0;
    while(left<right) {
        int currSum = currEle+input[left]+input[right];
        if(currSum < targetSum) {
            countall += right-left;
            for(int point=left+1; point<=right; point++) {
                trip.push_back(Triplets(currEle, input[left], input[point]));
            }
            left++;
        } else {
            right--;
        }
    }
    return countall;
}

void Solution::countTriplets() {
    sort(input.begin(), input.end());
    int ans=0;
    for(int index=0; index<len-2; index++) {
        ans += getCurrPairs(input[index], index+1);
    }
    cout<<"ans: "<<ans<<endl;
    for(int index=0; index<trip.size(); index++) {
        trip[index].show();
    }
}

int main() {
    Solution obj({-1, 4, 2, 1, 3}, 5);
    obj.countTriplets();
    return 0;
}