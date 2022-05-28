#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        vector<int> input;
        int len;
    public:
        Solution(vector<int> vec): input(vec) {
            len = input.size();
        }
        void swap(int x, int y);
        void showArray();
        void sortArray();
};

void Solution::swap(int x, int y) {
    int temp = input[x];
    input[x] = input[y];
    input[y] = temp;
}

void Solution::showArray() {
    for(int index=0; index<len; index++) {
        cout<<input[index]<<" ";
    }
    cout<<endl;
}

void Solution::sortArray() {
    int start=0, end=len-1;
    cout<<"start: "<<start<<" end: "<<end<<endl;
    for(int index=0; index<=end; index++) {
        if(input[index] == 0) {
            swap(index, start);
            start++;
        } else if (input[index] == 2) {
            swap(index, end);
            end--;
            index--;
        }
    }
    showArray();
}

int main() {
    Solution obj({2, 2, 0, 1, 2, 0});
    obj.sortArray();
    return 0;
}