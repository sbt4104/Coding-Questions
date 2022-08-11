#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX = 100001;
const ll INF = 1e17;
vector<ll> dp(N_MAX,INF);

int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll> vec(n);
    for(ll index=0; index<n; index++) {
        cin>>vec[index];
    }
    dp[0] = 0;
    dp[1] = abs(vec[1]-vec[0]);
    for(ll i=2; i<n; i++) {
        //cout<<"i: "<<i<<endl;
        for(ll j=i-1; j>=max((ll)0,i-k); j--) {
            //cout<<"j: "<<j<<" ";
            dp[i] = min(dp[i], dp[j] + abs(vec[i]-vec[j]));    
        }
        //cout<<endl;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}