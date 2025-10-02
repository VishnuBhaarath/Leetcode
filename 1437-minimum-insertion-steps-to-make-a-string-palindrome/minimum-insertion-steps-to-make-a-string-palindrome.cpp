class Solution {
public:
    

    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if((j-1)>=0){
                    dp[i][j]=dp[i+1][j-1];
                    }
                }
                else{
                    int val=dp[i+1][j];
                    if((j-1)>=0){
                        val=min(val,dp[i][j-1]);
                    }
                    dp[i][j]=1+val;
                }
            }
        }
      

      return dp[0][n - 1];
    }
};