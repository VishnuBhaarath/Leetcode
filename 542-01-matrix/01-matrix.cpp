class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
    
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 if(grid[i][j]==0){
                   // grid[i][j]=0;
                    q.push({i,j});
                 }
                 
            }
        }
        while(!q.empty()){
             int sz=q.size();
             ans+=1;
             while(sz>0){
                pair<int,int> p=q.front();
                sz-=1;
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x-1>=0){
                    if(grid[x-1][y]==1){
                        grid[x-1][y]=0;
                       
                        dp[x-1][y]=ans;
                    q.push({x-1,y});
                    }

                }

                 if(x+1<n){
                    if(grid[x+1][y]==1){
                        grid[x+1][y]=0;
                        
                         dp[x+1][y]=ans;
                    q.push({x+1,y});
                    }

                }

                if(y-1>=0){
                    if(grid[x][y-1]==1){
                        grid[x][y-1]=0;
                       
                        dp[x][y-1]=ans;
                    q.push({x,y-1});
                    }

                }

                if(y+1<m){
                    if(grid[x][y+1]==1){
                        grid[x][y+1]=0;
                         dp[x][y+1]=ans;
                       
                    q.push({x,y+1});
                    }

                }





             }
             
        }

      
        return dp;
    }
};