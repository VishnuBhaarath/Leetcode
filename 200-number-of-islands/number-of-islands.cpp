class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> adj;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    adj.push_back({i,j});
                }
            }
        }

        int cnt=0;
        map<pair<int,int>,int> umap;
        queue<pair<int,int>> q;
        for(int i=0;i<adj.size();i++){
           if(umap[{adj[i][0],adj[i][1]}]==0){
              q.push({adj[i][0],adj[i][1]});
              cnt+=1;
              umap[{adj[i][0],adj[i][1]}]+=1;
              while(!q.empty()){
                 int x=q.front().first;
                 int y=q.front().second;
                 q.pop();
                 if(x+1<n){
                    if(grid[x+1][y]=='1'){
                        if(umap[{x+1,y}]==0){
                            umap[{x+1,y}]+=1;
                            q.push({x+1,y});
                        }
                        
                    }
                 }
                 if(x-1 >=0){
                     if(grid[x-1][y]=='1'){
                        if(umap[{x-1,y}]==0){
                            umap[{x-1,y}]+=1;
                            q.push({x-1,y});
                        }
                     }
                 }
                 if(y-1>=0){
                    if(grid[x][y-1]=='1'){
                        if(umap[{x,y-1}]==0){
                            umap[{x,y-1}]+=1;
                            q.push({x,y-1});
                        }
                     }
                 }
                if(y+1<m){
                    if(grid[x][y+1]=='1'){
                        if(umap[{x,y+1}]==0){
                            umap[{x,y+1}]+=1;
                            q.push({x,y+1});
                        }
                     }
                 }
              }
           }
        }
        return cnt;
    }
};