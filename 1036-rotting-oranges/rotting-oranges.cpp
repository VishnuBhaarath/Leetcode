class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
           map<pair<int,int>,int> umap;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 if(grid[i][j]==2){
                    if(dp[i][j]==0){
                         dp[i][j]=1;
                         vector<vector<int>> dp1(n,vector<int>(m,0));
                         queue<pair<int,int>> q;
                      
                         q.push({i,j});
                       
                         while(!q.empty()){
                            int x=q.front().first;
                            int y=q.front().second;
                         
                            int temp=umap[{x,y}];
                            q.pop();
                            if((x-1)>=0){
                                if(grid[x-1][y]==1){
                                    if(dp1[x-1][y]==0){
                                        dp1[x-1][y]=1;
                                     //   grid[x-1][y]=2;
                                        if(umap[{x-1,y}]!=0){
                                            umap[{x-1,y}]=min(umap[{x-1,y}],temp+1);
                                        }
                                        else{
                                            umap[{x-1,y}]=temp+1;
                                        }
                                      //  ans=max(ans,umap[{x-1,y}]);
                                       
                                        q.push({x-1,y});
                                   }
                                }
                            }
                            if((x+1)<n){
                                 if(grid[x+1][y]==1){
                                    if(dp1[x+1][y]==0){
                                        dp1[x+1][y]=1;
                                       //grid[x+1][y]=2;
                                        if(umap[{x+1,y}]!=0){
                                            umap[{x+1,y}]=min(umap[{x+1,y}],temp+1);
                                        }
                                        else{
                                            umap[{x+1,y}]=temp+1;
                                        }
                                      //  ans=max(ans,umap[{x+1,y}]);
                                        q.push({x+1,y});
                                    }
                                }
                            }

                            if((y-1)>=0){
                                if(grid[x][y-1]==1){
                                    if(dp1[x][y-1]==0){
                                        dp1[x][y-1]=1;
                                       // grid[x][y-1]=2;
                                        if(umap[{x,y-1}]!=0){
                                            umap[{x,y-1}]=min(umap[{x,y-1}],temp+1);
                                        }
                                        else{
                                            umap[{x,y-1}]=temp+1;
                                        }
                                      //   ans=max(ans,umap[{x,y-1}]);
                                     
                                        q.push({x,y-1});
                                   }
                                }
                            }


                            if((y+1)<m){
                                if(grid[x][y+1]==1){
                                    if(dp1[x][y+1]==0){
                                        dp1[x][y+1]=1;
                                     //   grid[x][y+1]=2;
                                         if(umap[{x,y+1}]!=0){
                                            umap[{x,y+1}]=min(umap[{x,y+1}],temp+1);
                                        }
                                         else{
                                            umap[{x,y+1}]=temp+1;
                                        }
                                       // ans=max(ans,umap[{x,y+1}]);
                                        q.push({x,y+1});
                                  }
                                }
                            }


                           
                         }
                    }
                 }
            }
        }
       

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(umap[{i,j}]==0){
                        return -1;
                    }
                }
            }
           
        }
        for(auto x:umap){
          
            ans=max(ans,x.second);
        }
        return ans;
    }
};