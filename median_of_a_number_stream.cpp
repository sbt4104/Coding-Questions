/*
Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.
*/
#include<bits/stdc++.h>
using namespace std;

class MedianOfAStream{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void insertNum(int num) {
        if(maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        int sizeMaxHeap = maxHeap.size(), sizeMinHeap = minHeap.size();
        if(sizeMaxHeap>sizeMinHeap+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(sizeMaxHeap<sizeMinHeap){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    float findMedian() {
        int sizeMaxHeap = maxHeap.size(), sizeMinHeap = minHeap.size();
        if(sizeMaxHeap==sizeMinHeap) {
            return (minHeap.top()+maxHeap.top())/2.0;
        } else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianOfAStream obj;
    obj.insertNum(3);
    //obj.insertNum(1);
    cout<<"median: "<<obj.findMedian()<<endl;
    obj.insertNum(5);
    cout<<"median: "<<obj.findMedian()<<endl;
    obj.insertNum(4);   
    cout<<"median: "<<obj.findMedian()<<endl;
    return 0;
}