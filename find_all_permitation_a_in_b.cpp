#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        string inputStr="", searchStr="";
        int inputLen=0, searchLen=0;
        unordered_map<char, int> mainMap;
    public:
        Solution(string str1, string str2): inputStr(str1), searchStr(str2) {
            inputLen = inputStr.length();
            searchLen = searchStr.length();
        }
        void setMainMap();
        string isPresent();
};

void Solution::setMainMap() {
    for(int index=0; index<searchLen; index++) {
        mainMap[searchStr[index]]++;
    }
}

string Solution::isPresent() {
    setMainMap();
    int start=0, similarity=0;
    vector<int> answer;
    for(int end=0; end<inputLen; end++) {
        char curr=inputStr[end];
        if(mainMap.find(curr) != mainMap.end()) {
            mainMap[curr]--;
            if(mainMap[curr] == 0) {
                // this particular character (curr) is completely filled
                similarity++;
            }
        }

        if(similarity == searchLen) {
            answer.push_back(start);
        }

        if(end-start+1 >= searchLen) {
            curr = inputStr[start];
            if(mainMap.find(curr) != mainMap.end()) {
                if(mainMap[curr] == 0) {
                    similarity--;
                }
                mainMap[curr]++;
            }
            start++;
        }
    }
    for(int index=0; index<answer.size(); index++) {
        cout<<answer[index]<<" ";
    }
    cout<<endl;
    return answer.size() ? "yes" : "no";
}

int main() {
    Solution obj("abbcabc","abc");
    cout<<"ans: "<<obj.isPresent()<<endl;
    return 0;
}