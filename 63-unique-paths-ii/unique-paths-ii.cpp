class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        int n=dp.size();
        int m=dp[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==1){
                    dp[i][j]=-1;
                }
            }
        }
        if(dp[0][0]==-1){
            return 0;
        }
        if(dp[n-1][m-1]==-1){
            return 0;
        }
    dp[0][0]=1;
        for(int j=1;j<m;j++){
            if(dp[0][j]!=-1 && dp[0][j-1]!=-1){
                dp[0][j]+=dp[0][j-1];
            }

        }
    
        for(int i=1;i<n;i++){
            if(dp[i][0]!=-1 && dp[i-1][0]!=-1){
                dp[i][0]+=dp[i-1][0];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]!=-1){
                if(dp[i-1][j]!=-1){
                    dp[i][j]+=dp[i-1][j];
                }
                if(dp[i][j-1]!=-1){
                    dp[i][j]+=dp[i][j-1];
                }
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