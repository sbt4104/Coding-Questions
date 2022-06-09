/*
We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.
*/
#include<bits/stdc++.h>
using namespace std;

class DuplicateNumber{
    public:
        static void swap(vector<int> &vec, int i, int j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
        static  int findDuplicateNums(vector<int> &vec);
};

int DuplicateNumber::findDuplicateNums(vector<int> &vec) {
    int index=0;
    int ans;
    while(index < vec.size()) {
        int indexJ=vec[index]-1;
        if(vec[index]!=vec[indexJ]) {
            swap(vec, index, indexJ);
        } else {
            if(vec[index]!=(index+1)) {
                return vec[index];
            }
            index++;
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {2, 4, 1, 4, 4};
    cout<<"Repeating number: "<<DuplicateNumber::findDuplicateNums(vec)<<endl;
    return 0;
}