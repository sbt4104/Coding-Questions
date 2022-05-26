/*
 OPTIMISED: Given an array with positive numbers and a target number, find all of its contiguous subarrays whose product is less than the target number.
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
        void getSubarrays();
};

void Solution::getSubarrays() {
    int ans=0, left=0, right=0, prod=1;
    for(int right=0; right<len; right++) {
        prod *= input[right];
        while(prod >= targetProd && left<len) {
            prod /= input[left];
            left++;
        }

        //all subarrays between [left, right] have product less that targetprod
        for(int indexI=left; indexI<=right; indexI++) {
            for(int indexJ=indexI; indexJ<=right; indexJ++) {
                cout<<input[indexJ]<<" ";
            }
            ans++;
            cout<<endl;
        }
    }
    cout<<"ans: "<<ans<<endl;
}

int main() {
    Solution obj({2,3,4,5,6}, 120);
    obj.getSubarrays();
    return 0;
}