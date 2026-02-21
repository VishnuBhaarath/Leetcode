class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
    //  map<pair<int,int>,int> umap;
        queue<pair<int,int>> q;
        vector<vector<int>> v(n,vector<int>(m,0));
        int ans=0;
        vector<int> r={0,0,1,-1};
        vector<int> c={1,-1,0,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!=0 && v[i][j]==0){
                      q.push({i,j});
                      v[i][j]=1;
                      int cnt=0;
                     
                      while(!q.empty()){
                         pair<int,int> p=q.front();
                         q.pop();
                        
                         int x=p.first;
                         int y=p.second;
                         cnt+=grid[x][y];
                         for(int k=0;k<r.size();k++){
                            int x1=x+r[k];
                            int y1=y+c[k];
                            if((x1<n && x1>=0) && (y1<m && y1>=0)){
                                if(v[x1][y1]==0 && grid[x1][y1]!=0){
                                    v[x1][y1]=1;
                                    q.push({x1,y1});
                                   
                                }
                            }
                         }

                      }
                     
                  
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};