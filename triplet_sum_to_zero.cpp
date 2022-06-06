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
            right--;
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

/*
    
class Solution {
//This snippet takes care of cases where releated triplets are not allowed (follows the same pattern as given in leetcode)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());    
        vector<vector<int>> triplets;
        for(int index=0; index<(int)nums.size()-2; index++) {
            if(index>0 && nums[index]==nums[index-1]) {continue;}
            vector<vector<int>> curr = getTriplets(-nums[index], index+1, nums);
            triplets.insert(triplets.end(), curr.begin(), curr.end()); 
        }

        return triplets;
    }

    vector<vector<int>>  getTriplets(int sum,int index, vector<int> &nums) {
        int start=index, end=nums.size()-1;
        vector<vector<int>> triplets;
        while(start<end) {
            int currSum = nums[start]+nums[end]; 

            if(currSum == sum) {
                vector<int> currTriplet{-sum, nums[start], nums[end]};
                triplets.push_back(currTriplet);
                start++;
                end--;
                while(start<end && nums[start]==nums[start-1]) {
                    start++;
                }
                while(start<end && nums[end]==nums[end+1]) {
                    end--;
                }
            } else if(currSum < sum) {
                start++;
            } else {
                end--;
            }
        }
        return triplets;
    }
};
*/