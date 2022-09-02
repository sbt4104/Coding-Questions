#include<bits/stdc++.h>
using namespace std;

void getVal(int n) {
    int inner=1;
    vector<int> vec, sec;
    unordered_map<int, int> map;
    while(1) {
        int currInner=inner;
        int quot=inner/n;
        inner = inner - (n*quot);
        if(currInner >= n) {vec.push_back(quot);}
        if(map.find(inner)!=map.end()) {
            int index=map[inner];
            for(int i=index; i<vec.size(); i++) {
                sec.push_back(vec[i]);
            }
            break;
        }
        if(currInner<n && !map.empty()) {vec.push_back(0);}
        map[inner]=vec.size();
        inner*=10;
    }

    if(sec.size()==0) {sec.push_back(0); vec.push_back(0);}
    cout<<"0.";
    for(int i=0; i<vec.size(); i++) {
        cout<<vec[i];
    } cout<<" ";
    for(int i=0; i<sec.size(); i++) {
        cout<<sec[i];
    } cout<<endl;
}

int main() {
    int n;
    cin>>n;
    getVal(n);
    return 0;
}