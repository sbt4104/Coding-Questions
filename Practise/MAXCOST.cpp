#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[2001][2001];
const ll INF=1e12;

/*
    dp[i][j] denotes the maximum profit that can be achieved from index [i,j] (i<=j)
    dp[i][j] = max(rem*vec[i] + dp[i+1][j], rem*vec[j] + dp[i][j-1]);
    rem = n-(j-i);
    return dp[0][n-1]

    dp[0][0] = n*vec[0]
    dp[1][1] = n*vec[1]
    dp[2][2] = n*vec[2]
    ....

    dp[0][1] = max(rem*vec[0] + dp[1][1], rem*vec[1] + dp[0][0]);
    dp[0][2] = max(rem*vec[0] + dp[1][2], rem*vec[2] + dp[0][1])

    start from bottom up;
*/

int main() {
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(ll i=0; i<n; i++) {
        cin>>vec[i];
    }
    for(ll i=0; i<n; i++) {
        for(ll j=i; j<n; j++) {
            dp[i][j] = -INF; 
        }
    }

    for(ll i=0; i<n; i++) {
        dp[i][i] = n*vec[i];
    }

    for(ll i=n-1; i>=0; i--) {
        for(ll j=i+1; j<n; j++) {
            ll rem = n-(j-i);
            dp[i][j] = max(rem*vec[i] + dp[i+1][j], rem*vec[j] + dp[i][j-1]);
        }
    }

    cout<<dp[0][n-1]<<endl;
    return 0;
}