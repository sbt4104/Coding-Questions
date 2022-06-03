/*
Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval {
    public:
        int start,end;
        Interval(int p1, int p2): start(p1), end(p2) {}
        void showInterval() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class MergeIntervalClass{
    public:
        static vector<Interval> mergeInterval(vector<Interval> &input);
};

vector<Interval> MergeIntervalClass::mergeInterval(vector<Interval> &input) {
    int len=input.size();
    vector<Interval> ans;
    // sort based on start of the interval
    sort(input.begin(), input.end(), [](const Interval &x, const Interval &y) {return x.start <= y.start;});

    // start merging
    int start=input[0].start;
    int end=input[0].end;
    for(int index=1; index<len; index++) {
        if(input[index].start <= end) {
            end = max(input[index].end, end);
        } else {
            ans.push_back(Interval(start, end));
            start = input[index].start;
            end = input[index].end;
        }
    }
    ans.push_back(Interval(start, end));
    return ans;
}

int main() {
    vector<Interval> vec= {{1,4}, {2,6}, {3,5}}; //{{6,7}, {2,4}, {5,9}};
    vector<Interval> ans = MergeIntervalClass::mergeInterval(vec);
    for(int index=0; index<ans.size(); index++) {
        ans[index].showInterval();
    }
    return 0;
}