#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX=100001;
const ll INF = 1e17;
ll dp[N_MAX][3];
ll maxim(ll a, ll b, ll c) {
    return max(a, max(b,c));
}

/*
dp[i] = maximum sum till day i
dp[i] depends on dp[i-1] and state of (i-1) & (i-2)
dp[i][j] = maxim if last activity done is j
*/

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n), b(n), c(n);
    for(ll index=0; index<n; index++) {
        cin>>a[index]>>b[index]>>c[index];
    }

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    dp[1][0] = max(b[0], c[0])+a[1];
    dp[1][1] = max(a[0], c[0])+b[1];
    dp[1][2] = max(a[0], b[0])+c[1];

    for(ll i=2; i<n; i++) {
        for(ll j=0; j<3; j++) {
            // current activity is j, that means last 2 activity cant be j consecutively
            // can't be dp[i-1][j]
            dp[i][j]= max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            switch(j) {
                case 0:
                dp[i][j] += a[i]; break;
                case 1:
                dp[i][j] += b[i]; break;
                case 2:
                dp[i][j] += c[i]; break;
            }
        }
    }
    cout<<maxim(dp[n-1][0], dp[n-1][1], dp[n-1][2])<<endl;
    return 0;
}