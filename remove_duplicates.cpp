/*
    Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the new length of the array.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> input;
    public:
        Solution(vector<int> vec): input(vec) {}
        int removeDuplicates();
};

int Solution::removeDuplicates() {
    int point1=0, point2=1;
    for(int point1=1; point1<input.size(); point1++) {
        if(input[point1] != input[point1-1]) {
            input[point2]=input[point1];
            point2++;
        }
    }

    for(int index=0; index<input.size(); index++) {
        cout<<input[index]<<" ";
    }
    cout<<endl;
    return point2;
}

int main() {
    Solution obj({2, 2, 2, 11});
    cout<<"answer: "<<obj.removeDuplicates()<<endl;
    return 0;
}