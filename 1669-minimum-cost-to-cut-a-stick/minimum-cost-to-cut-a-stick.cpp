class Solution {
public:
   
    int minCost(int n, vector<int>& cuts) {
        //  sort(cuts.begin(), cuts.end());
        int i = 0;
        int j = n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size() - 1;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        // return func(cuts, 0, m, n,dp);
        for (int i = m; i >= 0; i--) {
            for (int j = i + 1; j <= m; j++) {
                int ans = INT_MAX;
                for (int k = 0; k < cuts.size(); k++) {
                    if (cuts[k] > cuts[i] && cuts[k] < cuts[j]) {

                        int sum = (cuts[j] - cuts[i]) +
                                  dp[i][k] +
                                  dp[k][j];
                        ans = min(ans, sum);
                    }
                }
                if (ans != INT_MAX) {
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][m];
    }
};