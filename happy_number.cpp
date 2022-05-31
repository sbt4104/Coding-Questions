/*
Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int num;
        Solution(int val): num(val) {}
        bool isHappy();
        int performSum(int val);
};

int Solution::performSum(int val) {
    int ans=0;
    while(val) {
        int curr = val%10;
        ans += curr*curr;
        val /= 10;
    }
    return ans;
}


bool Solution::isHappy() {
    int slow=num;
    int fast=num;

    do {
        slow = performSum(slow);
        fast = performSum(performSum(fast));
    } while(slow!=fast);

    /*
        this snippet is to get the start of the cycle
        int count=0;
        do {
            count++;
            slow = performSum(slow);
            fast = performSum(performSum(fast));
        } while(slow!=fast);

        int first=num, second=num;
        while(count--) {
            second = performSum(second);
        }

        while(first!=second) {
            first = performSum(first);
            second = performSum(second);
        }

        cout<<"start value: "<<first<<endl;
    */

    if(slow == 1) {
        return true;
    }
    return false;
}

int main() {
    Solution obj(12);
    cout<<"ans: "<<obj.isHappy()<<endl;    
    return 0;
}