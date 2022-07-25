/*
Range Minimum Query using sparse table
find minimum value between two indices
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAX_N = 100005;
const ll LOG = 17;
ll m[MAX_N][LOG];
ll vec[MAX_N];

ll query(ll a, ll b) {
    ll size = b-a+1,k=0;
    while((1<<(k+1)) <= size) {
        k++;
    }
    cout<<"k: "<<k<<endl;
    return min(m[a][k], m[b-(1<<k)+1][k]);
}

void precompute(int n) {
    for(ll index=1; index<LOG; index++) {
        for(ll pos=0; pos+(1<<index)-1<n; pos++) {
            m[pos][index]=min(m[pos][index-1], m[pos + (1<<(index-1))][index-1]);
        }
    }
}

int main() {
    ll n,q,a,b;
    cin>>n>>q;
    for(ll index=0; index<n; index++) {
        cin>>vec[index];
        m[index][0]=vec[index];
    }

    precompute(n);
    while(q--) {
        cin>>a>>b;
        cout<<query(a,b)<<endl;
    }

    return 0;
}