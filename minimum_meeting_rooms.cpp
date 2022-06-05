/*
Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int start, int end): start(start), end(end) {}
        void show() {cout<<"start: "<<start<<" end: "<<end<<endl;}
};

class RequiredRooms{
    public:
        struct endCompare{
            bool operator()(Interval &x, Interval &y) {return x.end > y.end;}
        };
        static int minRooms(vector<Interval> intervals);
};


int RequiredRooms::minRooms(vector<Interval> intervals) {
    int len=intervals.size();
    sort(intervals.begin(), intervals.end(), [](Interval &x, Interval &y) {return x.start <= y.start;});
    priority_queue<Interval, vector<Interval>, endCompare> minHeap;

    int ans=0;
    for(int index=0; index<len; index++) {
        // remove the intervals from minHeap who have ended before the current interval start
        while(!minHeap.empty() && intervals[index].start >= minHeap.top().end) {
            minHeap.pop();
        }

        minHeap.push(intervals[index]);
        ans = max(ans,  (int)minHeap.size());
    }

    return ans;
}

int main() {
    cout<<"ans: "<<RequiredRooms::minRooms({ {4,5}, {2,3}, {2,4}, {3,5} })<<endl;
    return 0;
}