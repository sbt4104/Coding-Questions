/*
Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.
*/
#include<bits/stdc++.h>
using namespace std;

class Quad{
    private:
        int q1,q2,q3,q4;
    public:
        Quad(int p1, int p2, int p3, int p4): q1(p1), q2(p2),  q3(p3), q4(p4) {}
        void show() {cout<<q1<<" "<<q2<<" "<<q3<<" "<<q4<<endl;}
};

class Solution{
    private:
        vector<int> input;
        int len, target;
        vector<Quad> ans;
    public:
        Solution(vector<int> vec, int tar): input(vec), target(tar) {
            len = input.size();
        }
        void getPair(int,int,int);
        void getQuads();
        void showAns();
};

void Solution::showAns() {
    for(int index=0; index<ans.size(); index++) {
        ans[index].show();
    }
}

void Solution::getPair(int first, int second, int index) {
    int start = index, end=len-1;
    while(start<end) {
        int currSum = first+second+input[start]+input[end];
        if(currSum == target) {
            ans.push_back(Quad(first, second, input[start], input[end]));
            start++;
        } else if(currSum < target) {
            start++;
        } else {
            end--;
        }
    }
}

void Solution::getQuads() {
    sort(input.begin(), input.end());
    for(int indexI=0; indexI<len; indexI++) {
        for(int indexJ=indexI+1; indexJ<len; indexJ++) {
            getPair(input[indexI], input[indexJ], indexJ+1);
        }
    }
    showAns();
}

int main() {
    Solution obj({2, 0, -1, 1, -2, 2}, 2);
    obj.getQuads();
    return 0;
}