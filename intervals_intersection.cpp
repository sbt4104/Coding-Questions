/*
Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int p1, int p2) : start(p1), end(p2) {}
        void showInterval() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class IntesectIntervalClass{
    public:
        static vector<Interval>  intersectInterval(vector<Interval> input1 , vector<Interval> input2);
};

vector<Interval>  IntesectIntervalClass::intersectInterval(vector<Interval> input1 , vector<Interval> input2) {
    vector<Interval> ans;
    int i=0 , j=0;
    int start=0, end=0;
    while(i<input1.size() && j<input2.size()) {
        //check for overlap
        if(!(input1[i].start>input2[j].end || input1[i].end<input2[j].start)) {
            start = max(input1[i].start, input2[j].start);
            end = min(input1[i].end, input2[j].end);
            ans.push_back({start, end});
        }

        if(input1[i].end < input2[j].end) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    vector<Interval> ans = IntesectIntervalClass::intersectInterval({{1,3}, {5,6}, {7,9}}, {{2,3}, {5,7}});
    for(int index=0; index<ans.size(); index++) {
        ans[index].showInterval();
    }
    return 0;
}