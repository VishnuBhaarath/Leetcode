class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         if(grid[0][0]==1){
            return 0;
         }
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
              
                if(grid[i][j]==1){
                    grid[i][j]=-1;
                }
                else if(i==0 || j==0){
                    if(i==0){
                        grid[i][j]=1;
                        if((j-1)>=0){
                        if(grid[i][j-1]==-1){
                            grid[i][j]=-1;
                        }}
                       
                    }
                    if(j==0){
                        grid[i][j]=1;
                        if((i-1)>=0){
                        if(grid[i-1][j]==-1){
                            grid[i][j]=-1;
                        }
                        }
                    }
                }
                else{
                    if(grid[i-1][j]!=-1){
                        grid[i][j]+=grid[i-1][j];
                    }
                    if(grid[i][j-1]!=-1){
                        grid[i][j]+=grid[i][j-1];
                    }
                    if(grid[i-1][j]==-1 && grid[i][j-1]==-1){
                        grid[i][j]=-1;
                    }
                }

            }
         }
         return max(0,grid[n-1][m-1]);
    }
};