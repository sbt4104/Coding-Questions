// Put maximum number of fruits in 2 separate baskets such that the subarray is contigous.
/*
Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> fruits(n);
    for(int index=0; index<n; index++) {
        cin>>fruits[index];
    }

    int start=0, answer = INT_MIN, sIndex = -1, eIndex = -1;
    unordered_map <string, int> countFruits;
    for(int end=0; end<n; end++) {
        // add fruit to the map
        countFruits[fruits[end]]++;

        // keep remove element from the start if total type of fruits exceed 2
        while(countFruits.size() > 2) {
            countFruits[fruits[start]]--;
            if(countFruits[fruits[start]] == 0) {
                countFruits.erase(fruits[start]);
            }
            start++;
        }
        if (answer < end-start+1) {
            answer = end-start+1;
            sIndex = start;
            eIndex = end;
        }
    }

    cout<<"answer: "<<answer<<endl<<"start index: "<<sIndex<<endl<<"last index: "<<eIndex<<endl;

    return 0;
}