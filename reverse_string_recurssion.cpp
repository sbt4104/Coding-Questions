#include<bits/stdc++.h>
using namespace std;

void reverseStr(string str, int index, string &ans) {
    if(index >= str.length()) {
        ans += str[index];
        return;
    }
    reverseStr(str, index+1, ans);
    ans += str[index];
}

int main() {
    string str="shubham";
    string ans="";
    reverseStr(str, 0, ans);
    cout<<"ans: "<<ans<<endl;
}