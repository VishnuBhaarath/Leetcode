class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        cout<<n;
        cout<<" ";
        cout<<m;
        cout<<" ";

        cout<<grid[n-1][m-1];
        if(grid[n-1][m-1]==1){
            return 0;
        }
        if(grid[0][0]==1){
            return 0;
        }
        if(n==1){
            if(m==1){
                if(grid[0][0]==0){
                    return 1;
                }
            }
        }
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(dp[i-1][0]==1 && grid[i][0]==0){
                dp[i][0]=1;
            }
        }
        for(int j=1;j<m;j++){
           
            if(dp[0][j-1]==1 && grid[0][j]==0){
                dp[0][j]=1;
            }
        }
        cout<<"next";
        
       for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }

for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return dp[n-1][m-1];
    }
};