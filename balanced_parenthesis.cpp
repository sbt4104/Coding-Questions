/*
For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.
*/

#include<bits/stdc++.h>
using namespace std;

class Parenthesis{
    public:
    static vector<string> getBalancedParenthesis(int N){
        vector<string> ans;
        queue<pair<string, pair<int,int> > > queue;
        queue.push(make_pair("", make_pair(0,0)));
        while(!queue.empty()) {
            pair<string, pair<int,int>> curr=queue.front();
            string currString=curr.first;
            int currOpenthesis=curr.second.first;
            int currClosethesis=curr.second.second;
            queue.pop();
            if(currClosethesis==N && currOpenthesis==N) {
                ans.push_back(currString);
            } else {
                if(currOpenthesis < N) {
                    queue.push(make_pair(currString+'(', make_pair(currOpenthesis+1, currClosethesis)));
                }

                if(currOpenthesis > currClosethesis) {
                    queue.push(make_pair(currString+')', make_pair(currOpenthesis, currClosethesis+1)));
                }
            }

        }
        return ans;
    }
};

int main() {
    vector<string> ans= Parenthesis::getBalancedParenthesis(3);
    for(auto str: ans) {
        cout<<str<<endl;
    }
    return 0;
}