#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX = 100001;
vector<ll> dp(N_MAX,0);

int main() {
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(ll index=0; index<n; index++) {
        cin>>vec[index];
    }

    dp[1] = abs(vec[1]-vec[0]);
    for(ll index=2; index<n; index++) {
        dp[index] = min(dp[index-2]+abs(vec[index]-vec[index-2]), dp[index-1] + abs(vec[index]-vec[index-1]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}