#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(ll index=0; index<n; index++) {
        cin>>vec[index];
    }

    ll l=0, r=n-1, ans=0;

    while(r>=l) {
        ll mid=(r+l)/2;

        if(mid==0 || vec[mid]>vec[mid-1]) {
            ans=mid;
            l=mid+1;
        } else {
            r= mid-1;
        }
    }
    cout<<"ans: "<<vec[ans]<<endl;
    return 0;
}