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
    int len=input.size(), index=0;
    vector<Interval> ans;
    int start=interval.start, end=interval.end;
    // skip all the intervals which are less than given interval
    while(start > input[index].end) {
        ans.push_back(input[index]);
        index++;
    }

    while(index<len && end >= input[index].start) {
        start = min(start, input[index].start);
        end = max(end, input[index].end);
        index++;
    }

    ans.push_back({start, end});

    while(index<len) {
        ans.push_back(input[index]);
        index++;
    }
    return ans;
}

int main() {
    vector<Interval> ans = InsertIntervalClass::insertInterval({{1,3}, {5,7}, {8,12}}, {4,10});
    for(int index=0; index<ans.size(); index++) {
        ans[index].showInterval();
    }
    return 0;
}