/*
Given an array, find the average of all contiguous subarrays of size ‘K’ in it.
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<float> avg;
    for(int index=0; index<n; index++) {
        cin>>arr[index];
    }

    float currSum = 0.0;
    int start = 0;

    for(int end=0; end<n; end++) {
        currSum += arr[end];

        if(end >= k - 1) {
            avg.push_back(currSum/k);
            currSum -= arr[start];
            start++;
        }
    }

    for(int index=0; index<avg.size(); index++) {
        cout<<avg[index]<<" ";
    }
    return 0;
}