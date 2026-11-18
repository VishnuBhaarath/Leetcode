class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]=='1'){
                     if(dp[i][j]==0){
                        dp[i][j]=1;
                        grid[i][j]='0';
                        queue<pair<int,int>> q;
                        q.push({i,j});
                        cnt+=1;
                        while(!q.empty()){
                            pair<int,int> p=q.front();
                            q.pop();
                            int x=p.first;
                            int y=p.second;
                            if(x-1>=0){
                                if(grid[x-1][y]=='1'){
                                    if(dp[x-1][y]==0){
                                        dp[x-1][y]=1;
                                        q.push({x-1,y});
                                    }
                                }
                            }
                            if(x+1<n){
                                 if(grid[x+1][y]=='1'){
                                    if(dp[x+1][y]==0){
                                        dp[x+1][y]=1;
                                        q.push({x+1,y});
                                    }
                                }
                            }
                            if(y-1>=0){
                                 if(grid[x][y-1]=='1'){
                                    if(dp[x][y-1]==0){
                                        dp[x][y-1]=1;
                                        q.push({x,y-1});
                                    }
                                }
                            }

                             if(y+1<m){
                                 if(grid[x][y+1]=='1'){
                                    if(dp[x][y+1]==0){
                                        dp[x][y+1]=1;
                                        q.push({x,y+1});
                                    }
                                }
                            }
                        }
                     }
                 }
            }
        }
        return cnt;
    }
};