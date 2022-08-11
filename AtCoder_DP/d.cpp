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

dp[W] = dp[W-w[0]] + v[0]
dp[W-1] = dp[W-1-w[0]] + v[0]
dp[W-2] = dp[W-2-w[0]] + v[0]
dp[W-3] = dp[W-3-w[0]] + v[0]

doesnt have a specific order, can do it in any order (0->n OR N->0) order of weights matter, weight w depends on weight less than it, eventually converges
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
            if(j+weight[i] > w) {continue;}
            dp[j+weight[i]] = max(dp[j+weight[i]], dp[j]+ values[i]);
        }
    }

    ll ans=dp[0];
    for(ll j=0; j<=w; j++) {
        ans = max(ans, dp[j]);
    }

    cout<<ans<<endl;
    return 0;
}