/*
We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
*/
#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
        int start, end, load;
        Job(int start, int end, int load): start(start), end(end), load(load) {}
        void showJob() {cout<<"start: "<<start<<"  end: "<<end<<" load: "<<load<<endl;}
};

class CpuLoad{
    public:
        struct endCompare {
            bool operator()(const Job &x, const Job &y) {return x.end > y.end;}
        };
        static int getMaxLoad(vector<Job> jobs);
};

int CpuLoad::getMaxLoad(vector<Job> jobs){
    int start = jobs[0].start, end=jobs[0].end, maxLoad=jobs[0].load, len=jobs.size();
    sort(jobs.begin(), jobs.end(), [](const Job &x, const Job &y) {return x.start < y.start;});
    
    int globalMax=0, currMax=0;
    priority_queue<Job, vector<Job>, endCompare> minHeap;
    for(int index=0; index<len; index++) {
        int currJob=0;
        while(!minHeap.empty() && jobs[index].start >= minHeap.top().end) {
            currMax -= minHeap.top().load;
            minHeap.pop();
        }

        minHeap.push(jobs[index]);

        currMax += jobs[index].load;
        globalMax = max(globalMax, currMax);
    }
    return globalMax;
}

int main() {
    cout<<"ans: "<<CpuLoad::getMaxLoad( { {1,4,2}, {2,4,1}, {3,6,5} })<<endl;
    return 0;
}