/*
We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
*/
#include<bits/stdc++.h>
using namespace std;

class MissingNumber{
    public:
        static void swap(vector<int> &vec, int i, int j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
        static  vector<int> findMissingNums(vector<int> &vec);
};

vector<int> MissingNumber::findMissingNums(vector<int> &vec) {
    int index=0;
    vector<int> ans;
    while(index<vec.size()) {
        int indexJ = vec[index]-1;
        if(vec[index] != vec[indexJ]) {
            swap(vec, index, indexJ);
        } else {
            index++;
        }
    }

    for(int index=0; index<vec.size(); index++) {
        if(vec[index] != index+1) {
            ans.push_back(index+1);
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {2, 3, 1, 8, 2, 3, 5, 1};
    vector<int> ans = MissingNumber::findMissingNums(vec);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl;
    return 0;
}