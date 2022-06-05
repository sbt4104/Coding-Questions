/*
For ‘K’ employees, we are given a list of intervals representing the working hours of each employee. Our goal is to find out if there is a free interval that is common to all employees. You can assume that each list of employee working hours is sorted on the start time.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int start, int end):start(start), end(end) {}
        void showInterval() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class empTime{
    public:
        static vector<Interval> getFreeTime(vector<vector<Interval>> empTable);
};

vector<Interval> empTime::getFreeTime(vector<vector<Interval>> empTable) {
    vector<Interval> intervals, ans;
    for(int index=0; index<empTable.size();  index++) {
        for(auto currInterval: empTable[index]) {
            intervals.push_back(currInterval);
        }
    }

    sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) {return x.start < y.start;});
    int start=intervals[0].start, end=intervals[0].end;
    for(int index=1; index<intervals.size(); index++) {
        if(intervals[index].start > end) {
            // no overlap found
            ans.push_back({end, intervals[index].start});
        }
        end = intervals[index].end;
    }

    return ans;
}

int main() {
    vector<Interval> ans = empTime::getFreeTime({{{1,3}, {2,4}}, {{3,5}, {7,9}}});
    for(auto curr: ans) {
        curr.showInterval();
    }
    return 0;
}