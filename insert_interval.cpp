/*
Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int p1, int p2) : start(p1), end(p2) {}
        void showInterval() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class InsertIntervalClass{
    public:
        static vector<Interval>  insertInterval(vector<Interval> input , Interval interval);
};

vector<Interval>  InsertIntervalClass::insertInterval(vector<Interval> input , Interval interval) {
    int len=input.size();
    vector<Interval> ans;
    int start=interval.start, end=interval.end, flag=0;
    for(int index=0; index<len; index++) {
        if(!(start > input[index].end || end < input[index].start)) {
            //overlap found
            start = min(start, input[index].start);
            end = max(end, input[index].end);
            flag=1;
        } else {
            flag ? ans.push_back(Interval(start, end)) :  ans.push_back(input[index]);
            flag=0;
        }
    }
    flag ? ans.push_back(Interval(start, end)) :  ans.push_back(input[len-1]);
    return ans;
}

int main() {
    vector<Interval> ans = InsertIntervalClass::insertInterval({{2,3}, {5,7}}, {1,4});
    for(int index=0; index<ans.size(); index++) {
        ans[index].showInterval();
    }
    return 0;
}