/*
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.
*/
#include<bits/stdc++.h>
using namespace std;

class CorruptPair{
    public:
        static void swap(vector<int> &vec, int i, int j) {
            int temp = vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
        static vector<int> findCorruptPair(vector<int> &vec);
};

vector<int> CorruptPair::findCorruptPair(vector<int> &vec) {
    int index=0;
    vector<int> ans;
    while(index<vec.size()) {
        int indexJ=vec[index]-1;
        if(vec[index] != vec[indexJ]) {
            swap(vec, index, indexJ);
        } else {
            index++;
        }
    }

    for(int index=0; index<vec.size(); index++){
        if(vec[index]!= index+1) {
            ans={vec[index],index+1};
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {3, 1, 2, 3, 6, 4};
    vector<int> ans = CorruptPair::findCorruptPair(vec);
    cout<<"ans: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}