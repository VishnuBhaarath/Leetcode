class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int t=0;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 if(grid[i][j]==2){
                    grid[i][j]=0;
                    q.push({i,j});
                 }
                 else if(grid[i][j]==1){
                    t+=1;
                 }
            }
        }
        while(!q.empty()){
             int sz=q.size();
             while(sz>0){
                pair<int,int> p=q.front();
                sz-=1;
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x-1>=0){
                    if(grid[x-1][y]==1){
                        grid[x-1][y]=0;
                        t-=1;
                    q.push({x-1,y});
                    }

                }

                 if(x+1<n){
                    if(grid[x+1][y]==1){
                        grid[x+1][y]=0;
                        t-=1;
                    q.push({x+1,y});
                    }

                }

                if(y-1>=0){
                    if(grid[x][y-1]==1){
                        grid[x][y-1]=0;
                        t-=1;
                    q.push({x,y-1});
                    }

                }

                if(y+1<m){
                    if(grid[x][y+1]==1){
                        grid[x][y+1]=0;
                        t-=1;
                    q.push({x,y+1});
                    }

                }





             }
             if(q.size()>0){
                ans+=1;
             }
        }

        if(t!=0){
            return -1;
        }
        return ans;
    }
};