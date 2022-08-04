/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Solution:
let dp[i][j] be the total number of ways to get sum i and last chosen be j
dp[0][0] = 1;
if we have dp[i][j] = SUM(dp[i-coins[k]][k]) (k from 0->j)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1][coins.size()];
        
        // number of ways to get sum zero is always 1
        for(int i=0; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                dp[i][j]=0;
            }
        }
        
        for(int i=0; i<=amount; i++) {
            if(i%coins[0]==0) {
                dp[i][0] = 1;
            }
        }
        for(int i=0; i<coins.size(); i++) {
            dp[0][i]=1;
        }
        for(int i=1; i<=amount; i++) {
            for(int j=1; j<coins.size(); j++) {
                // get sum using j available denominations    
                dp[i][j] = dp[i][j-1];    
                if(i-coins[j] < 0) {continue;}
                dp[i][j] += dp[i-coins[j]][j];
            }
        }

        return dp[amount][coins.size()-1];
    }
};