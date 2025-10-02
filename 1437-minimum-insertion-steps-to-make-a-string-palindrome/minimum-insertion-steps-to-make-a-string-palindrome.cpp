class Solution {
public:
    int minInsertions(string s) {
         int n = s.size();
        
        // Create DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: when j <= i, dp[i][j] = 0
        // Already initialized to 0
        
        // Fill the DP table
        // Since we go from i to i+1 and j to j-1, we need:
        // - i goes from n-1 to 0 (backwards)
        // - j goes from 0 to n-1 (forwards)
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(j <= i) {
                    dp[i][j] = 0;  // Base case
                } else if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};