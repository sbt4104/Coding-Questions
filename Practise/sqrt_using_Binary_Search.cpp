#include<bits/stdc++.h>
using namespace std;

int main() {
    double eps=0.001, num;
    cin>>num;

    double l=0, r=num;
    while(r-l > eps) {
        float mid = l + (r-l)/2;
        if(mid*mid > num) {
            r=mid;
        } else {
            l=mid;
        }
    }

    cout<<"sqrt("<<num<<") : "<<l+(r-l)/2<<endl;
    return 0;
}