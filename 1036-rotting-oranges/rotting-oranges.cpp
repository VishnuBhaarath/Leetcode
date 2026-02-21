class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        int tc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                  if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                  }
                  if(grid[i][j]==1){
                    tc+=1;
                  }
            }
        }
        vector<int> row={1,-1,0,0};
        vector<int> col={0,0,1,-1};
        int cnt=0;
        int val=0;
        while(!q.empty()){
            int sz=q.size();
            
            while(sz>0){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                for(int i=0;i<4;i++){
                     int x1=x+row[i];
                     int y1=y+col[i];
                     if((x1>=0 && x1<n) && (y1>=0 && y1<m)){
                        if(grid[x1][y1]==1){
                            q.push({x1,y1});
                            grid[x1][y1]=0;
                            val+=1;
                        }
                     }
                }
                sz-=1;
            }
            if(!q.empty()){
                cnt+=1;
            }
        }
        if(val!=tc){
            return -1;
        }
return cnt;
        
    }
};