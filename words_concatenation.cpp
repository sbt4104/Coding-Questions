#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string inputStr;
        vector<string> patterns;
        int inputLen, ptrnLen, szpat;
        unordered_map<string, int> mainMap;
    public:
        Solution(string str, vector<string> vec): inputStr(str), patterns(vec) {
            inputLen = inputStr.length();
            ptrnLen = patterns.size();
            szpat = patterns[0].length();
            cout<<"inputStr: "<<inputStr<<" inputLen: "<<inputLen<<" ptrnLen: "<<ptrnLen<<" szpat: "<<szpat<<endl;
            for(int index=0; index<ptrnLen; index++) {
                cout<<patterns[index]<<" ";
            }
            cout<<endl;
        }
        void fillMainMap();
        void getMatchingStr();
};

void Solution::fillMainMap() {
    for(int index=0; index<ptrnLen; index++) {
        mainMap[patterns[index]]++;
    }
}
void Solution::getMatchingStr() {
    fillMainMap();
    vector<int> storeIndex;
    for(int start=0; start<=inputLen-ptrnLen*szpat; start++) {
        // check in substring from start index till start+ptrnLen*szpat
        unordered_map<string, int> currMap;
        int index;
        for(index=start; index<start+ptrnLen*szpat; index=index+szpat) {
            // get the first word of the szpat size
            string curr = inputStr.substr(index, szpat);
            // cout<<"start: "<<start<<" index: "<<index<<" szpat: "<<szpat<<" curr: "<<curr<<endl;
            if(mainMap.find(curr) == mainMap.end()) {
                break;
            }
            currMap[curr]++;
            if(currMap[curr] > mainMap[curr]) {
                break;
            }
        }
        if(index >= start+ptrnLen*szpat) {
            storeIndex.push_back(start);
        }
    }
    cout<<"answer: ";
    for(int index=0; index<storeIndex.size(); index++) {
        cout<<storeIndex[index]<<" ";
    }
    cout<<endl;
}

int main() {
    Solution obj("atecatecate", {"cat", "ate"});
    obj.getMatchingStr();
    return 0;    
}