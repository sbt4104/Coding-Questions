/*
For ‘K’ employees, we are given a list of intervals representing the working hours of each employee. Our goal is to find out if there is a free interval that is common to all employees. You can assume that each list of employee working hours is sorted on the start time (use heap data structure).
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int start, int end):start(start), end(end) {}
        void showInterval() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class OurStruct{
    public:
        Interval interval;
        int row, col;
        OurStruct(Interval interval, int row, int col): interval(interval), row(row), col(col) {}
        void show() {cout<<"interval: "<<interval.start<<" "<<interval.end<<" i: "<<row<<" j: "<<col<<endl;}
};

class empTime{
    public:
        struct structCompare{
            bool operator()(const OurStruct &x, const OurStruct &y) {return x.interval.start > y.interval.start;};
        };
        static vector<Interval> getFreeTime(vector<vector<Interval>> empTable);
};

vector<Interval> empTime::getFreeTime(vector<vector<Interval>> empTable) {
    vector<Interval> ans;
    priority_queue<OurStruct, vector<OurStruct>, structCompare> minHeap;

    for(int index=0; index<empTable.size(); index++) {
        minHeap.push({empTable[index][0], index, 0});
    }

    Interval previousInterval = minHeap.top().interval;
    while(!minHeap.empty()) {
        OurStruct curr = minHeap.top();
        minHeap.pop();

        // check if there is no overlap
        if(previousInterval.end < curr.interval.start) {
            ans.push_back({previousInterval.end, curr.interval.start});
            previousInterval=curr.interval;
        } else {
            if(previousInterval.end < curr.interval.end) {
                previousInterval = curr.interval;
            }
        }

        if(curr.col < empTable[curr.row].size()-1 ) {
            minHeap.push({ {empTable[curr.row][curr.col + 1]}, curr.row, curr.col+1});
        }
    }

    return ans;
}

int main() {
    vector<Interval> ans = empTime::getFreeTime({{{1,3}, {5,6}}, {{2,3}, {6,8}}});
    for(auto curr: ans) {
        curr.showInterval();
    }
    return 0;
}