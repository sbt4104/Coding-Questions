#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int index=0; index<n; index++) {
        cin>>arr[index];
    }

    int start = 0, currSum = 0, ans = INT_MIN;
    for(int end=0; end<n; end++) {
        currSum += arr[end];
        if(end >= k-1) {
            ans = max(ans, currSum);
            currSum -= arr[start];
            start++;
        }
    }

    cout<<"\nminimum sum subarray of size "<<k<<" is: "<<ans<<endl;
    return 0;
}