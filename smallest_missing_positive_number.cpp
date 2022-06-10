/*
Given an unsorted array containing numbers, find the smallest missing positive number in it.
*/
#include<bits/stdc++.h>
using namespace std;

class MissingNumbers{
    public:
        static void swap(vector<int> &vec, int i, int j) {
            int temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
        static int smallestMissingPos(vector<int> &vec);
};

int MissingNumbers::smallestMissingPos(vector<int> &vec) {
    int index=0, ans=-1;
    while(index < vec.size()) {
        int indexJ=vec[index]-1;
        if(vec[index]>0 && vec[index]<vec.size()+1 && vec[index]!=vec[indexJ]) {
            swap(vec, index, indexJ);
        } else {
            index++;
        }
    }

    for(int index=0; index<vec.size(); index++) {
        if(vec[index]!=index+1) {
            ans=index+1;
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> vec={3, 2, 5, 1};
    cout<<"ans: "<<MissingNumbers::smallestMissingPos(vec)<<endl;
    return 0;
}