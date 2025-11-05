class Solution {
public:
    int func(vector<int>& cuts, int i, int j, int n,vector<vector<int>>&dp) {
        if (cuts[i] >= cuts[j]) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = 0; k < cuts.size(); k++) {
            if (cuts[k] > cuts[i] && cuts[k] < cuts[j]) {

                int sum = (cuts[j] - cuts[i]) + func(cuts, i, k, n,dp) +
                          func(cuts, k, j, n,dp);
                ans = min(ans, sum);
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
      
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
      //  sort(cuts.begin(), cuts.end());
        int i = 0;
        int j = n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size()-1;
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return func(cuts, 0, m, n,dp);
    }
};