/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int k;
    cin>>str>>k;
    map<char, int> charCount;
    int start = 0, len = str.length(), maxLen = INT_MIN;

    for(int end=0; end<len; end++) {
        charCount[str[end]]++;

        while(charCount.size() > k) {  
            charCount[str[start]]--;
            if(charCount[str[start]] == 0) {
                charCount.erase(str[start]);
            }
            start++;
        } 
        
        maxLen = max(maxLen, end-start+1);
    }

    cout<<"answer: "<<maxLen<<endl;
    return 0;
}