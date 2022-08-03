#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll n,m;
    cin>>n>>m;
    ll arr[n][m];
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    ll dp[n][m];
    
    //fill first row
    dp[0][0]=arr[0][0];
    for(ll i=1; i<m; i++) {
        dp[0][i]=dp[0][i-1] + arr[0][i];
    }

    //fill first col
    for(ll i=1; i<n; i++) {
        dp[i][0]=dp[i-1][0] + arr[i][0];
    }

    for(ll i=1; i<n; i++) {
        for(ll j=1; j<m; j++) {
            dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"ans: "<<dp[n-1][m-1]<<endl;

    return 0;
}