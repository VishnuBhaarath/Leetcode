class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                 if(matrix[i][j]=='1'){
                    int val=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
                    dp[i+1][j+1]=1+val;
                    ans=max(ans,dp[i+1][j+1]);
                 }
            }
        }
        return ans*ans;
    }
};