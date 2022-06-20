/*
Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.
*/


/*
Solution: 
Maintain 2 heaps, maxendheap, maxStartHeap, so that we traverse from max end to min end and search for next max start consecutively
pick the top element from maxendheap, remove top from min heap and keep searching, after we find the next min start, mark it and push it back to min heap 
do this while maxheap is not empty
*/
#include<bits/stdc++.h>
using namespace std;

class Interval {
    public:
    int start, end;
    Interval(int start=-1, int end=-1) {
        this->start=start;
        this->end=end;
    }
};

class OurStruct{
    public:
    Interval interval;
    int index;
    OurStruct(Interval interval, int index) {
        this->interval=interval;
        this->index=index;
    }
};

class NextInterval {
    public:
    struct compareStart{
        bool operator()(OurStruct &x, OurStruct &y) {return x.interval.start < y.interval.start;};
    };

    struct compareEnd{
        bool operator()(OurStruct &x, OurStruct &y) {return x.interval.end < y.interval.end;};
    };

    vector<int> getNextInterval(vector<Interval> intervals) {
        int len = intervals.size();
        vector<int> ans(len,-1);
        priority_queue<OurStruct, vector<OurStruct>, compareStart> maxStartHeap;
        priority_queue<OurStruct, vector<OurStruct>, compareEnd> maxEndHeap;

        for(int index=0; index<len; index++) {
            maxEndHeap.push(OurStruct(intervals[index], index));
            maxStartHeap.push(OurStruct(intervals[index], index));
        }

        while(!maxEndHeap.empty()) {
            auto topEnd=maxEndHeap.top();
            maxEndHeap.pop();

            if(maxStartHeap.top().interval.start >= topEnd.interval.end) {
                auto topStart = maxStartHeap.top();
                maxStartHeap.pop();

                while(!maxStartHeap.empty() && maxStartHeap.top().interval.start >= topEnd.interval.end) {
                    topStart = maxStartHeap.top();
                    maxStartHeap.pop();
                }

                ans[topEnd.index]= topStart.index;
                maxStartHeap.push(topStart);
            }
        }
        return ans;
    }
};

int main() {
    NextInterval obj;
    vector<int> ans=obj.getNextInterval({{3,4}, {1,5}, {4,6}});
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;
    return 0;
}