class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=INT_MIN;
        int val1=grid[0][0];
        for(int i=1;i<n;i++){
            ans=max(ans,grid[i][0]-val1);
            val1=min(val1,grid[i][0]);
        }
        val1=grid[0][0];
        for(int j=1;j<m;j++){
             ans=max(ans,grid[0][j]-val1);
             val1=min(val1,grid[0][j]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                 int val=min(grid[i-1][j],grid[i][j-1]);
                 val=min(val,grid[i-1][j-1]);
                 int diff=grid[i][j]-val;
                 ans=max(ans,diff);
                 grid[i][j]=min(val,grid[i][j]);
            }
        }

       

        

        return ans;
    }
};