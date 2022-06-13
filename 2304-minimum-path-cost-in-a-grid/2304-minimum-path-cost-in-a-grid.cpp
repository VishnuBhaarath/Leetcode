class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp=grid;
        int ans=-1;
        int n=grid.size();
        for(int i=0;i<grid.size()-1;i++){
            for(int j=0;j<grid[0].size();j++){
                for(int k=0;k<grid[0].size();k++){
                    if(j==0){
                    dp[i+1][k]=dp[i][j]+grid[i+1][k]+moveCost[grid[i][j]][k];
                    }
                    else{
                        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+grid[i+1][k]+moveCost[grid[i][j]][k]);
                    }
        
                }
            }
        }

       
            for(int j=0;j<grid[0].size();j++){
                if(ans==-1){
                    ans=dp[n-1][j];
                }
                else{
                    ans=min(ans,dp[n-1][j]);
                }
               
            }
         
        
        return ans;
    }
};