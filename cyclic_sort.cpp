/*
We are given an array containing ‘n’ objects. Each object, when created, was assigned a unique number from 1 to ‘n’ based on their creation sequence. This means that the object with sequence number ‘3’ was created just before the object with sequence number ‘4’.

Write a function to sort the objects in-place on their creation sequence number in O(n)O(n) and without any extra space. For simplicity, let’s assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.
*/

#include<bits/stdc++.h>
using namespace std;

class cyclicClass{
    public:
    static void swap(int indexI, int indexJ, vector<int> &vec) {
        int temp = vec[indexI];
        vec[indexI] = vec[indexJ];
        vec[indexJ] = temp;
    }
    static void cyclicSort(vector<int> &vec);
};

void cyclicClass::cyclicSort(vector<int> &vec) {
    int len=vec.size();
    for(int index=0; index<len; index++) {
        while(vec[index]!=(index+1)) {
            swap(index, vec[index]-1, vec);
        }
    }
}

int main() {
    vector<int> vec = {5,3,4,2,1};
    cyclicClass::cyclicSort(vec);
    for(int index=0; index<vec.size(); index++) {
        cout<<vec[index]<<" ";
    }
    cout<<endl;
    return 0;
}