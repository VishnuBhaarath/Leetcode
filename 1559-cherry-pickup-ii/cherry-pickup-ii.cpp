class Solution {
public:
    vector<vector<vector<int>>>dp;
    int func(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid){
        if(i==n){
            return 0;
        }
        if(j1<0 || j2<0){
            return 0;
        }
        if(j1>=m || j2>=m){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        if(j1==j2){
           return dp[i][j1][j2]=grid[i][j1]+max({func(i+1,j1,j2-1,n,m,grid),func(i+1,j1,j2,n,m,grid),func(i+1,j1,j2+1,n,m,grid),
            func(i+1,j1-1,j2-1,n,m,grid),func(i+1,j1-1,j2,n,m,grid),func(i+1,j1-1,j2+1,n,m,grid),
            func(i+1,j1+1,j2-1,n,m,grid),func(i+1,j1+1,j2,n,m,grid),func(i+1,j1+1,j2+1,n,m,grid)});
        }
        else{
  return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+max({func(i+1,j1,j2-1,n,m,grid),func(i+1,j1,j2,n,m,grid),func(i+1,j1,j2+1,n,m,grid),
            func(i+1,j1-1,j2-1,n,m,grid),func(i+1,j1-1,j2,n,m,grid),func(i+1,j1-1,j2+1,n,m,grid),
            func(i+1,j1+1,j2-1,n,m,grid),func(i+1,j1+1,j2,n,m,grid),func(i+1,j1+1,j2+1,n,m,grid)});
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(m+1,vector<int>(m+1,-1));
        dp.resize(n+1,v);
        return func(0,0,m-1,n,m,grid);
        
    }
};