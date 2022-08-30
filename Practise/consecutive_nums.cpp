#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input={3,3,2,2,5,5,5,5,5,3,3,3,2,2};
    int value=0;
    vector<vector<int>> vec(16);

    for(int i=0; i<input.size(); i++) {
        vec[input[i]].push_back(i+1);
    }

    for(int i=1; i<=15; i++) {
        vector<int> curr=vec[i];
        int consecutive=0;
        cout<<"i; "<<i<<endl;
        for(int j=0; j<curr.size(); j++) {
            int prevCons=consecutive;
            if(consecutive==0 || curr[j]==(curr[j-1]+1)) {
                consecutive++;
            } else {
                consecutive=1;
            }
            cout<<consecutive<<endl;
            if((j==(curr.size()-1) && consecutive==i) || (curr[j]!=(curr[j-1]+1) && prevCons==i)) {
                cout<<"in\n";
                value++;
            }
        }
    }
    cout<<value<<endl;
    return 0;
}