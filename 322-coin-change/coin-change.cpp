class Solution {
public:
    vector<vector<long long int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n + 1, vector<long long int>(amount + 2, 0));
        if(amount==0){
            return 0;
        }
        // int ans= func(coins,amount,0,0);
        int ans = -1;
        sort(coins.begin(), coins.end());
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                if (j == coins[i]) {
                    dp[i][j] = 1;
                } else if (j > coins[i]) {
                    if (dp[i][j - coins[i]] > 0) {
                        if (dp[i][j] == 0) {
                            dp[i][j] = 1 + dp[i][j - coins[i]];
                        } else {
                            if(1+dp[i][j-coins[i]]<dp[i][j]){
                                dp[i][j]=1 + dp[i][j - coins[i]];
                            }
                            
                        }
                    }
                    if (dp[i + 1][j - coins[i]] > 0) {
                        if (dp[i][j] == 0) {
                            dp[i][j] = 1 + dp[i + 1][j - coins[i]];
                        } else {
                            if(dp[i + 1][j - coins[i]]+1<dp[i][j]){
                            dp[i][j] = 1 + dp[i + 1][j - coins[i]];
                            }
                            
                        }
                    }
                    if (dp[i + 1][j] != 0) {
                        if(dp[i][j]==0){
                            dp[i][j]=dp[i+1][j];
                        }
                        dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                    }
                }
                if (j == amount) {
                    if (dp[i][j] != 0) {
                        if (ans == -1) {
                            ans = dp[i][j];
                        } else {
                            if(dp[i][j]<ans){
                                ans=dp[i][j];
                            }
                            
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};