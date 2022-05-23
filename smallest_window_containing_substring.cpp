#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string inputStr, searchStr;
        int inputLen, searchLen;
        map<char, int> mainMap;
    public:
        Solution(string str1, string str2) : inputStr(str1), searchStr(str2) {
            inputLen = inputStr.length();
            searchLen = searchStr.length();
        }
        void fillMainMap();
        int getSmallestStr();
};

void Solution::fillMainMap() {
    for(int index=0; index<searchLen; index++) {
        mainMap[searchStr[index]]++;
    }
}

int Solution::getSmallestStr() {
    fillMainMap();
    int start=0, similarity=0, ans=INT_MAX, storeX=-1, storeY=-1;
    for(int end=0; end<inputLen; end++) {
        char curr = inputStr[end];
        if(mainMap.find(curr) != mainMap.end()) {
            mainMap[curr]--;
            if(mainMap[curr] >= 0) {
                similarity++;
            }
        }

        while(similarity == searchLen) {
            if(ans > (end-start+1)) {
                ans = end-start+1;
                storeX=start;
                storeY=end;
            }
            char sChar = inputStr[start]; 
            if(mainMap.find(sChar) != mainMap.end()) {
                if(mainMap[sChar] == 0) {similarity--;}
                mainMap[sChar]++;
            }
            start++;
        }

    }
    for(int index=storeX; index<=storeY; index++) {
        cout<<inputStr[index];
    }
    cout<<endl;
    return ans;
}

int main() {
    Solution obj("abdcaaa", "abc");
    cout<<"answer: "<<obj.getSmallestStr()<<endl;
    return 0;
}