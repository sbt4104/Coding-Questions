/*
https://codeforces.com/contest/5/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MAX_N = 1000005;
const ll LOG = 20;
ll LOGN=0;

ll m[MAX_N][LOG];
vector<ll> a(MAX_N,0);
vector<ll> pw(MAX_N, 0);

void preprocess(ll n) {
    for(ll index=1; index<LOGN; index++) {
        for(ll pos=0; pos+(1<<index)-1<n; pos++) {
            m[pos][index] = min(m[pos][index-1], m[pos+(1<<(index-1))][index-1]);
        }        
    }
}

ll query(ll a, ll b) {
    ll k=pw[b-a+1];
    return min(m[a][k], m[b-(1<<k)+1][k]);
}

int main() {
    string str;
    //std::getline(std::cin,str);
    cin>>str;
    ll len=str.length();
    unordered_map<ll, vector<ll>> mp;
    vector<ll> visited(len+1,0);

    LOGN=0;
    while(1<<(LOGN) <= len+1) {LOGN++;}
    // prepare a & mp: a stores the difference of '(' & ')', mp stores the indices have same a
    mp[0].push_back(0);
    m[0][0]=a[0];
    for(ll index=1; index<=len; index++) {
        a[index] = (str[index-1]=='(' ? a[index-1]+1 : a[index-1]-1);
        mp[a[index]].push_back(index);
        m[index][0]=a[index];
    }

    preprocess(len+1);
    for (ll i = 2; i <= len+1; ++i) pw[i] = pw[i / 2] + 1;
    ll maxLen=0, freq=1;
    for(ll index=0; index<=len; index++) {
        if(visited[index]==1) {continue;};
        vector<ll> curr = mp[a[index]];
        if(curr.size()==1) {continue;}

        for(ll pos=0; pos<curr.size(); pos++) {
            visited[curr[pos]]=1;
            ll l=pos;
            ll r=curr.size()-1;
            bool flag=false;
            while(r>=l) {
                ll mid=(r+l)/2;
                ll val=query(curr[pos],curr[mid]);
                if(val >= a[index]) {
                    l=mid+1;
                    flag=true;
                } else {
                    r=mid-1;
                }
            }
            if(flag==false) {continue;}
            ll currLen = curr[l-1]-curr[pos];
            if(currLen > maxLen) {
                maxLen=currLen;
                freq=1;
            } else if(currLen==maxLen) {
                freq++;
            }
        }
    }
    if(maxLen==0) {freq=1;}
    cout<<maxLen<<" "<<freq;

    return 0;
}