/*
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
*/
#include<bits/stdc++.h>
using namespace std;

class Triplets{
    public:
        int first,second,third;
        Triplets(int t1, int t2, int t3) {
            first=t1;
            second=t2;
            third=t3;
        }
        void show() {
            cout<<first<<" "<<second<<" "<<third<<endl;
        }
};

class Solution {
    private:
        vector<int> input;
        int len;
        vector<Triplets> ans;
    public:
        Solution(vector<int> vec): input(vec) {
            len = input.size();
        }
        void pairSum(int, int);
        void getTriplets();
};

void Solution::pairSum(int giveSum, int index) {
    int left=index;
    int right=len-1;
    while(left<right) {
        int currSum = input[left]+input[right];
        if(currSum == giveSum) {
            Triplets trip(-giveSum, input[left], input[right]);
            ans.push_back(trip);
            left++;
        } else if (currSum < giveSum) {
            left++;
        } else {
            right--;
        }
    }
}

void Solution::getTriplets() {
    sort(input.begin(), input.end());
    for(int index=0; index<len-2; index++) {
        int searchSum = -input[index];
        pairSum(searchSum, index+1);
    }

    for(int index=0; index<ans.size(); index++) {
        ans[index].show();
    }
}

int main() {
    Solution obj({-3, 0, 1, 2, -1, 1, -2});
    // -3,-2,-1,0,1,1,2
    obj.getTriplets();
    return 0;
}