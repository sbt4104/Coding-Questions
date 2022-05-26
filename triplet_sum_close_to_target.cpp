/*
Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.
*/
#include<bits/stdc++.h>
using namespace std;

class Triplets {
    public:
        int first, second, third;
        Triplets(int t1=0,int t2=0,int t3=0): first(t1), second(t2), third(t3) {}
        void show() {
            cout<<first<<" "<<second<<" "<<third<<endl;
        }
        int sum() {
            return first+second+third;
        }
};

class Solution {
    private:
        vector<int> input;
        int len,target, closestDiff=INT_MAX;
        Triplets trip;
    public:
        Solution(vector<int> vec, int tar): input(vec), target(tar) {
            len = input.size();
        }
        void getTriplets();
        void getClosePair(int,int);
};

void Solution::getClosePair(int currEle, int index) {
    int left=index, right=len-1;
    while(left<right) {
        int currSum = currEle+input[left]+input[right];
        if(currSum == target) {
            closestDiff = target-currSum;
            trip = Triplets(currEle, input[left], input[right]);
            return;
        }

        if(abs(target-currSum) < closestDiff) {
            closestDiff=abs(target-currSum);
            trip = Triplets(currEle, input[left], input[right]);
        }

        if(currSum > target) {
            right--;
        } else {
            left++;
        }
    }
}

void Solution::getTriplets() {
    sort(input.begin(), input.end());
    for(int index=0; index<len-2; index++) {
        getClosePair(input[index], index+1);
    }
    trip.show();
    cout<<"ans: "<<trip.sum()<<endl;
}

int main() {
    Solution obj({-3, -1, 1, 2}, 1);
    obj.getTriplets();
    return 0;
}