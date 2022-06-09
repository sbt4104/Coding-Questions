/*
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.
*/
#include<bits/stdc++.h>
using namespace std;

class DuplicateNumber{
    public:
    static void swap(vector<int> &vec, int i, int j) {
        int temp=vec[i];
        vec[i]=vec[j];
        vec[j]=temp;
    }
    static vector<int> getDuplicates(vector<int> &vec) {
        vector<int> ans;
        int index=0;
        while(index<vec.size()) {
            int indexJ=vec[index]-1;
            if(vec[index]!=vec[indexJ]) {
                swap(vec, index, indexJ);
            } else {
                index++;
            }
        }

        for(int index=0; index<vec.size(); index++) {
            if(vec[index] != index+1) {
                ans.push_back(vec[index]);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> vec = {3, 4, 4, 5, 5};
    vector<int> ans = DuplicateNumber::getDuplicates(vec);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;
    return 0;
}