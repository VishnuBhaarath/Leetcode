class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp=grid;
        int num1=100;
        int num2=100;
        int idx1=-1;
        int idx2=-1;
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]<=num1){
                num2=num1;
                idx2=idx1;
                num1=grid[0][j];
                idx1=j;
            }
            else if(grid[0][j]<=num2){
                num2=grid[0][j];
                idx2=j;
            }
        }
       
        for(int i=1;i<grid.size();i++){
             int num3=INT_MAX;
             int num4=INT_MAX;
             int idx3=-1;
             int idx4=-1;
            for(int j=0;j<grid[i].size();j++){
                if(j!=idx1){
                    dp[i][j]=grid[i][j]+num1;
                }
                else if(j!=idx2){
                    dp[i][j]=grid[i][j]+num2;
                }
                if(dp[i][j]<=num3){
                    num4=num3;
                    idx4=idx3;
                    num3=dp[i][j];
                    idx3=j;
                }
                else if(dp[i][j]<=num4){
                    num4=dp[i][j];
                    idx4=j;
                }
            }
            num1=num3;
            idx1=idx3;
            num2=num4;
            idx2=idx4;
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return num1;
        
    }
};