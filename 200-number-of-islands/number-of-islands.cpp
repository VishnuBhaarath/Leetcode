class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
           // code here
   
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        vector<int> row={1,-1,0,0};
        vector<int> col={0,0,1,-1};
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
             
                     queue<pair<int,int>> q;
                     q.push({i,j});
                 
                     grid[i][j]='0';
                     cnt+=1;
                     while(!q.empty()){
                         int x=q.front().first;
                         int y=q.front().second;
                         q.pop();
                         
                         for(int k=0;k<4;k++){
                             int x1=x+row[k];
                             int y1=y+col[k];
                             
                             if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]=='1')
                             {
                            
                                 grid[x1][y1]='0';
                                 q.push({x1,y1});
                             }
                         }
                     }
                     
                 }
            }
        }
   
        return cnt;
    }
};