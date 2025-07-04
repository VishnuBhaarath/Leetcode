class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
       
        int ans=0;
        
        for(int i=0;i<dp.size();i++){
          for(int j=0;j<dp[i].size();j++){
            if(i==0 || j==0){
                if(matrix[i][j]=='1'){
                        ans=max(ans,1);
                        dp[i][j]=1;
                 }
                }
                else{
                if(matrix[i][j]=='1'){
                    ans=max(ans,1);
                    int val=min(dp[i-1][j],dp[i][j-1]);
                    val=min(val,dp[i-1][j-1]);
                    dp[i][j]=1+val;
                    ans=max(ans,dp[i][j]);
                }}
            }
           
        }
        return ans*ans;
    }
};