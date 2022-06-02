/*
We are given an array containing positive and negative numbers. Suppose the array contains a number ‘M’ at a particular index. Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’ indices. You should assume that the array is circular which means two things:
*/

#include<bits/stdc++.h>
using namespace std;

class CircularArray{
    public:
    vector<int> input;
    int len;
    CircularArray(vector<int> vec): input(vec) {
        len=input.size();
    }
    bool isCycle();
    int nextMove(int);
};

int CircularArray::nextMove(int curr) {
    int nextMove;
    if(curr + input[curr] < len) {
        nextMove=curr+input[curr];
    } else {
        nextMove = curr+input[curr]-len;
        nextMove %=len;
    }
    return curr==nextMove ? -1: nextMove;
}

// 0 1 2 3 4 5
bool CircularArray::isCycle() {
    vector<int> visited(len);

    for(int index=0; index<len; index++) {
        if(visited[index]) continue;
        int slow=index, fast=index, cyc=1, nextIndex;

        while(cyc) {
            // if direction of cycle changes, then break;
           if(input[index]*input[slow] < 0 || input[index]*input[fast] < 0) {break;}
            visited[slow] = visited[fast]=1;
            slow=nextMove(slow);
            fast=nextMove(nextMove(fast));

            if(slow == -1) {break;}
            if(slow==fast) {
                //cycle found
                cout<<"cycle found at index: "<<index<<endl;
                return true;
            }
        }
    }
    cout<<"cycle not found\n";
    return false;
}

int main() {
    CircularArray obj({2, 1, -1, -2});
    obj.isCycle();
    return 0;
}