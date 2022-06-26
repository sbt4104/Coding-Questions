/*
Given a string, find all of its permutations preserving the character sequence but changing case.
use queue and reduce time complexity by avoiding the vector erase method
*/
#include<bits/stdc++.h>
using namespace std;

class StringPermutations{
    public:
    static vector<string> getAllPermutations(string input){
        vector<string> ans;
        string temp="";
        int len=input.length();
        queue<string> permute;
        permute.push("");
        for(int index=0; index<len; index++){

            char currChar = input[index];
            int size=permute.size();
            while(size--) {
                string curr = permute.front();
                permute.pop();
                
                bool flag = (curr.length() == input.length()-1 ? true : false);
                if(currChar <= '9' && currChar >= '0') {
                    flag ? ans.push_back(curr+currChar): permute.push(curr+currChar);
                } else {
                    if(currChar <= 'z' && currChar >= 'a') {
                        temp = currChar+'A'-'a';
                        flag ? ans.push_back(curr+temp):permute.push(curr+temp);
                    } else {
                        temp=currChar+'a'-'A';
                        flag ? ans.push_back(curr+temp):permute.push(curr+temp);
                    }
                    flag ? ans.push_back(curr+currChar) : permute.push(curr+currChar);
                }
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