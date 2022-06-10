/*
Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.
*/
#include<bits/stdc++.h>
using namespace std;

class MissingNumbers{
    private:
        static void swap(vector<int> &vec, int i, int j) {
            int temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
    public:
        static vector<int> findKMissing(vector<int> &vec, int k) {
            int index=0;
            unordered_map<int,int> map;
            vector<int> ans;
            while(index<vec.size()) {
                int indexJ=vec[index]-1;
                if(vec[index]>0 && vec[index]<=vec.size() && vec[index]!=vec[indexJ]) {
                    swap(vec, index, indexJ);
                } else {
                    index++;
                }

                if(vec[index]> vec.size()) {
                    map[vec[index]]=1;
                }
            }

            for(int index=0; index<vec.size(); index++) {
                if(vec[index]!=index+1 && ans.size()<k) {
                    ans.push_back(index+1);
                }
            }

            int val = vec[vec.size()-1]+1;
            while(ans.size() < k) {
                if(map.find(val)==map.end()) {
                    ans.push_back(val);
                }
                val++;                
            }
            return ans;
        }
};

int main() {
    vector<int> vec={-2, -3, 4};
    vector<int> ans = MissingNumbers::findKMissing(vec, 2);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<" ";
    }
    cout<<endl; 
    return 0;
}