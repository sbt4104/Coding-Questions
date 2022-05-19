#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string input;
    public:
        void getInput() {
            cin>>input;
        }
        int maxUniqueString() {
            unordered_map<char, int> lastIndex;
            int start=0, ans = INT_MIN, sIndex = -1,eIndex = -1;
            for(int end=0; end<input.length(); end++) {
                
                // if current charater is already present in string
                if(lastIndex.find(input[end]) != lastIndex.end()) {
                    //set start properly
                    start = lastIndex[input[end]]+1;
                }
                
                if(ans <= end-start+1) {
                    ans = end-start+1;
                    sIndex = start;
                    eIndex = end;
                }
                lastIndex[input[end]] = end;
            }

            cout<<"startIndex: "<<sIndex<<endl<<"lastIndex: "<<eIndex<<endl;
            return ans;
        }
};
int main() {
    Solution currObj;
    currObj.getInput();
    cout<<currObj.maxUniqueString()<<endl;
    currObj.getInput();
    cout<<currObj.maxUniqueString()<<endl;

    return 0;
}