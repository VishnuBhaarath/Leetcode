class Solution {
public:
   
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,INT_MAX));
    
        for(int i=0;i<n;i++){
          
            for(int j=1;j<=(i+1);j++){
                
                if(i==0){
                   dp[i][j]=j*satisfaction[i];
                }
                else{
                    int val1=j*satisfaction[i];
                    if(dp[i-1][j-1]!=INT_MAX){
                        val1+=dp[i-1][j-1];
                    }
                    int val2=dp[i-1][j];
                    dp[i][j]=val1;
                    if(val2!=INT_MAX){
                        dp[i][j]=max(dp[i][j],val2);
                    }
              
                }
            }
            
        }
        
        int ans=0;
        for(int j=0;j<=n;j++){
            if(dp[n-1][j]!=INT_MAX){
                
                ans=max(ans,dp[n-1][j]);
            }
        }
        return ans;
    }
};