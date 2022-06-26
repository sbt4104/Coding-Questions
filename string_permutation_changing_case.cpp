/*
Given a string, find all of its permutations preserving the character sequence but changing case.
*/
#include<bits/stdc++.h>
using namespace std;

class StringPermutations{
    public:
    static vector<string> getAllPermutations(string input){
        vector<string> ans;
        string temp="";
        int len=input.length();
        ans.push_back(temp);
        for(int index=0; index<len; index++){
            char currChar = input[index];
            int size=ans.size();
            while(size--) {
                string curr=ans[0];
                if(currChar <= '9' && currChar >= '0') {
                    ans.push_back(curr+currChar);
                } else {
                    if(currChar <= 'z' && currChar >= 'a') {
                        temp = currChar+'A'-'a';
                        ans.push_back(curr+temp);
                    } else {
                        temp=currChar+'a'-'A';
                        ans.push_back(curr+temp);
                    }
                    ans.push_back(curr+currChar);
                }
                ans.erase(ans.begin());
            }
        }
        return ans;
    }
};
int main() {
    vector<string> ans = StringPermutations::getAllPermutations("ab7c");
    for(auto str: ans) {
        cout<<str<<endl;
    }
    return 0;
}