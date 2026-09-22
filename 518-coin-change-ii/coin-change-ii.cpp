class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unsigned long long int n = coins.size();

        vector<vector<unsigned long long int>> dp(n + 1, vector<unsigned long long int>(amount + 1, 0));

       
        for ( long long int i = 0; i <= n; i++) {
            dp[i][amount] = 1;
        }

        for (long long int i = n - 1; i >= 0; i--) {
            for (long long int sum = amount - 1; sum >= 0; sum--) {

                dp[i][sum] = dp[i + 1][sum];

                if (sum + coins[i] <= amount) {
                    dp[i][sum] += dp[i][sum + coins[i]];
                }
            }
        }

        return dp[0][0];
    }
};