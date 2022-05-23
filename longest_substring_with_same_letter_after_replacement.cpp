/*
Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string input;
        int k;
    public:
        void getInput(string str, int k) {
            input=str;
            this->k = k;
        }
        int longestSubstring() {
            int ans=INT_MIN, maxFrequency=INT_MIN, start=0;
            unordered_map<char, int> countFrequency;

            for(int end=0; end<input.length(); end++) {
                countFrequency[input[end]]++;
                maxFrequency = max(maxFrequency, countFrequency[input[end]]);

                if(end-start+1-maxFrequency > k) {
                    countFrequency[input[start]]--;
                    start++;
                }

                ans = max(ans,end-start+1);
            }
            return ans;
        }
};

int main() {
    Solution obj;
    obj.getInput("aaab",0);
    cout<<"answer: "<<obj.longestSubstring()<<endl;
    return 0;
}