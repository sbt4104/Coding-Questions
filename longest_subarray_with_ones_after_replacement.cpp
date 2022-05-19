// replace only zeroes with 1 and then calculate the maxcount
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> input;
        int k;
    public:
        void getInput(vector<int> inp, int k) {
            input = inp;
            this->k = k;
        }
        int longestSubarray() {
            int ans=INT_MIN, maxFrequency = INT_MIN, start=0;
            int countFrequency = 0; // measures the countn of 1 in the given window

            for(int end=0; end<input.size(); end++) {
                if(input[end] == 1) {
                    countFrequency++;
                }
                maxFrequency = max(maxFrequency, countFrequency);
                if(end-start+1-maxFrequency > k) {
                    if(input[start]==1) {
                        countFrequency--;
                    }
                    start++;
                }

                ans = max(ans, end-start+1);
            }
            return ans;
        }
};

int main() {
    Solution obj;
    vector<int> curr{0,1,1,1,1};
    obj.getInput(curr, 2);
    cout<<obj.longestSubarray()<<endl;
    return 0;
}