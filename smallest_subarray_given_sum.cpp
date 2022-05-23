/*
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,givenSum;
    cin>>n>>givenSum;
    vector<int> arr(n);
    for(int index=0; index<n; index++) {
        cin>>arr[index];
    }

    int start = 0, len = INT_MAX, currSum = 0, givenLen= INT_MAX;
    for(int end=0; end<n; end++) {
        currSum += arr[end];

        while(currSum >= givenSum) {
            givenLen = min(givenLen, end-start+1);
            currSum -= arr[start];
            start++;
        }
    }

    cout<<"answer: "<<givenLen<<endl;
    return 0;
}