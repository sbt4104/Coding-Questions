/*
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        vector<int> input;
        int len;
    public:
        Solution(vector<int> vec): input(vec) {
            len = input.size();
        }
        int getSmallestArr();
};

int Solution::getSmallestArr() {
    int left=0, right=len-1;
    // move left towards right
    while(input[left] < input[left+1] && left<len-1) {
        left++;
    }

    // move right towards left
    while(input[right] > input[right-1] && right>0) {
        right--;
    }

    int small=input[left], big=input[left];
    for(int index=left; index<=right; index++) {
        small = min(small, input[index]);
        big = max(big, input[index]);
    }

    while(input[left-1]>small && left>0) {
        left--;
    }

    while(input[right+1]<big && right<left-1) {
        right++;
    }

    return right-left+1;
}

int main() {
    Solution obj({3, 2, 1});
    cout<<"ans: "<<obj.getSmallestArr()<<endl;
    return 0;
}