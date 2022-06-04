/*
Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
*/
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int start, int end): start(start), end(end) {}
};

class ConflictingApp{
    public:
        static bool checkConflicts(vector<Interval> intervals);
};

bool ConflictingApp::checkConflicts(vector<Interval> intervals){
    sort(intervals.begin(), intervals.end(), [](Interval &x, Interval &y) {return x.start <= y.start;});
    int start=intervals[0].start, end=intervals[0].end;
    for(int index=1; index<intervals.size(); index++) {
        if(intervals[index].start <= end) {
            //overlap found
            return false;
        } else {
            start=intervals[index].start;
            end=intervals[index].end;
        }
    }

    return true;
}

int main() {
    if(ConflictingApp::checkConflicts({ {4,5}, {2,3}, {3,6} })) {
        cout<<"can attend all the events\n";
    } else {
        cout<<"cannot attend all the events\n";
    }
}