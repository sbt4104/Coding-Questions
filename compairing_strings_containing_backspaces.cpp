/*
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        string str1, str2;
        int len1, len2;
    public:
        Solution(string s1, string s2): str1(s1), str2(s2) {
            len1=str1.length();
            len2=str2.length();
        }
        bool isSame();
};

bool Solution::isSame() {
    int end1=len1-1, end2=len2-1, count1=0, count2=0;
    char charStr1, charStr2;
    while(end1>=0 && end2>=0) {
        //get the next element of str1 from back
        while(str1[end1] =='#') {
            count1=0;
            while(str1[end1] == '#') {
                end1--;
                count1++;
            }
            end1 -= count1;
        }
        charStr1 = str1[end1];

        //get the next element of str3 from back
        while(str2[end2] =='#') {
            count2=0;
            while(str2[end2] == '#') {
                end2--;
                count2++;
            }
            end2 -= count2;
        }
        charStr2 = str2[end2];
        if(charStr1 != charStr2) {
            return false;
        }
        end1--, end2--;
    }
    return true;
}

int main() {
    Solution obj("xy#z", "xzz#");
    cout<<obj.isSame()<<endl;
    return 0;
}