/*
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.
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
    static int findMissingEle(vector<int> &vec);
};

int cyclicClass::findMissingEle(vector<int> &vec) {
    int len=vec.size();
    for(int index=0; index<len; index++) {
        while(vec[index] < vec.size() && vec[index]!=index) {
            swap(index, vec[index], vec);
        }
    }

    int ans;
    for(int index=0; index<vec.size(); index++) {
        if(vec[index]!=index) {
            ans=index;
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {5,3,2,1,0};
    int num=cyclicClass::findMissingEle(vec);
    cout<<"ans:  "<<num<<endl;
    return 0;
}