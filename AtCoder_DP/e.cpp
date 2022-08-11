#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX = 100;
const ll W_MAX = 100001;
const ll INF = 1e17;
vector<ll> dp(W_MAX, INF);

/*
dp[i] = minimum weight for a given sum of value i
dp[i] = dp[i-values[i]] + weight[i];
*/

int main() {
    ll n,w;
    cin>>n>>w;
    vector<ll> weight(n), values(n);
    ll sumVal=0;
    for(ll index=0; index<n; index++) {
        cin>>weight[index]>>values[index];
        sumVal+=values[index];
    }

    dp[0]=0;
    for(ll i=0; i<n; i++) {
        for(ll j=sumVal; j>=0; j--) {
            if(j+values[i] > sumVal) {continue;}
            dp[j+values[i]] = min(dp[j+values[i]], dp[j]+weight[i]);
        }
    }
    ll ans=0;
    for(ll i=0; i<=sumVal; i++) {
        if(dp[i]<=w) {
            ans=max(ans, i);
        }
    }
    cout<<ans<<endl;
    return 0;
}