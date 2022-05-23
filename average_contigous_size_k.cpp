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
    if(k>n) {
        return -1;
    }
    float currSum = 0.0;
    for(int index=0; index<k; index++) {
        currSum += arr[index];
    }

    avg.push_back(currSum/k);
    for(int index=k; index<n; index++) {
        currSum -= arr[index-k];
        currSum += arr[index];
        avg.push_back(currSum/5);
    }

    for(int index=0; index<avg.size(); index++) {
        cout<<avg[index]<<" ";
    }
    cout<<endl;
    return 0;
}