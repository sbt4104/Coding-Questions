/*
Given a set of investment projects with their respective profits, we need to find the most profitable projects. We are given an initial capital and are allowed to invest only in a fixed number of projects. Our goal is to choose projects that give us the maximum profit.

We can start an investment project only when we have the required capital. Once a project is selected, we can assume that its profit has become our capital.
*/
#include<bits/stdc++.h>
using namespace std;

class MaximiseCapital{
    public:
    struct compareCapitals {
        bool operator()(pair<int, int> &x, pair<int, int> &y) {return x.first > y.first;};
    };
    struct compareProfits {
        bool operator()(pair<int, int> &x, pair<int, int> &y) {return y.first > x.first;};
    };

    int maximiseCapital(vector<int> capitals, vector<int> profits, int initialCapital, int numProjects) {
        int currCapital=initialCapital;

        // need to fetch capital with minimum value, use min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, compareCapitals> capitalHeap;

        // need to fetch profits with maximum value, use max heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, compareProfits> profitHeap;

        // push capitals to capitalHeap
        for(int index=0; index<profits.size(); index++) {
            capitalHeap.push(make_pair(capitals[index], index));
        }

        // lets finish the required projects
        for(int index=0; index<numProjects; index++) {
            while(!capitalHeap.empty() && currCapital >= capitalHeap.top().first) {
                int currIndex=capitalHeap.top().second;
                profitHeap.push(make_pair(profits[currIndex], currIndex));
                capitalHeap.pop();
            }

            if(profitHeap.empty()) {
                break;
            }
            currCapital += profitHeap.top().first;
            profitHeap.pop();
        }

        return currCapital;
    }
};

int main() {
    MaximiseCapital obj;
    cout<<"ans: "<<obj.maximiseCapital({0,1,2,3}, {1,2,3,5}, 0, 3)<<endl;
    return 0;
}