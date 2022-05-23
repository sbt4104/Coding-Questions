/*
Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> input;
        int sum;
    public:
        Solution(vector<int> vec, int sum): input(vec), sum(sum){};
        void checIfSumPresent();
};

void Solution::checIfSumPresent() {
    int start=0, end=input.size()-1;
    
    while(true) {
        int curr = input[start]+input[end]; 
        if(curr == sum) {
            cout<<"found: "<<start<<" , "<<end<<endl;
            return;
        } else if(curr < sum) {
            start++;
        } else {
            end--;
        }
    }
    cout<<"not found\n";
}

int main() {
    Solution obj({2,5,9,11}, 11);
    obj.checIfSumPresent();
    return 0;
}