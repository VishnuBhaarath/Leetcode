class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m+1,0);
        vector<vector<int>> dp(n+1,v);
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(dp[i][j]==1){
                    ans=max(ans,1);
                    int val=min(dp[i-1][j],dp[i][j-1]);
                    val=min(val,dp[i-1][j-1]);
                    dp[i][j]=1+val;
                    ans=max(ans,dp[i][j]);
                }
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return ans*ans;
    }
};