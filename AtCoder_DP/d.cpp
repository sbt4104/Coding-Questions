#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX = 100;
const ll W_MAX = 100001;
const ll INF = 1e17;
vector<ll> dp(W_MAX, -INF);

/*
dp[i] = max sum of value for given weight i

dp[i] => dp[i-weight[j]] + values[i];

dp[w] = dp[0-w[0]] + v[0]
dp[w] = dp[0-w[0]] + v[0]
*/

int main() {
    ll n,w;
    cin>>n>>w;
    vector<ll> weight(n), values(n);
    for(ll index=0; index<n; index++) {
        cin>>weight[index]>>values[index];
    }

    dp[0]=0;
    for(ll i=0; i<n; i++) {
        for(ll j=w; j>=0; j--) {
            if(j-weight[i] < 0) {continue;}
            dp[j] = max(dp[j-weight[i]] + values[i], dp[j]);
        }
    }

    ll ans=dp[0];
    for(ll j=0; j<=w; j++) {
        ans = max(ans, dp[j]);
    }

    cout<<ans<<endl;
    return 0;
}