class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      map<pair<int,int>,int> umap;
        queue<pair<int,int>> q;
        int cnt=0;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && umap[{i,j}]==0){
                      q.push({i,j});
                      umap[{i,j}]+=1;
                      cnt+=1;
                      while(!q.empty()){
                         pair<int,int> p=q.front();
                         q.pop();
                         int x=p.first;
                         int y=p.second;
                         for(int i=0;i<r.size();i++){
                            int x1=x+r[i];
                            int y1=y+c[i];
                            if((x1<n && x1>=0) && (y1<m && y1>=0)){
                                if(umap[{x1,y1}]==0 && grid[x1][y1]=='1'){
                                    umap[{x1,y1}]=1;
                                    q.push({x1,y1});
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