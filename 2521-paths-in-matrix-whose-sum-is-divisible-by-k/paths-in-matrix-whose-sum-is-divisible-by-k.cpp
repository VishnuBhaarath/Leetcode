class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>> dp;
        vector<vector<int>> dp1(m+1,vector<int>(k+1,0));
        dp.resize(n+1,dp1);
        int r= grid[0][0]%k;
        dp[0][0][r]=1;
        int mod=1e9+7;

        for(int j=1;j<m;j++){
            int r1=grid[0][j]%k;
           // dp[0][j][r1]=1;
            for(int l=0;l<k;l++){
                 if(dp[0][j-1][l]!=0){
                    int r2=r1+l;
                    if(r1+l>=k){
                        r2=(r1+l)%k;
                    }
                    dp[0][j][r2]=1;
                 }
            }
        }

        for(int i=1;i<n;i++){
             int r1=grid[i][0]%k;
             for(int l=0;l<k;l++){
                 if(dp[i-1][0][l]!=0){
                    int r2=r1+l;
                    if(r1+l>=k){
                        r2=(r1+l)%k;
                    }
                    dp[i][0][r2]=1;
                 }
             }
        }
        cout<<"val";
    

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int r1=grid[i][j]%k;
                
                for(int l=0;l<k;l++){
                     if(dp[i-1][j][l]!=0){
                        int r2=r1+l;
                        if(r2>=k){
                            r2=(r1+l)%k;
                        }
                        dp[i][j][r2]+=dp[i-1][j][l];
                     }
                     if(dp[i][j-1][l]!=0){
                        int r2=r1+l;
                        if(r2>=k){
                            r2=(r1+l)%k;
                        }
                        dp[i][j][r2]+=dp[i][j-1][l];
                        dp[i][j][r2]%=mod;
                     }
                }

            }
        }


        return dp[n-1][m-1][0];
    }
};