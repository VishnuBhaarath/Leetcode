class Solution {
public:
    void bfs(const vector<vector<int>>& heights,vector<vector<bool>>& ocean,queue<pair<int,int>>& q){
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(pair<int,int> dir:dirs){
                int row = p.first + dir.first;
                int col = p.second + dir.second;
                if(row < 0 || col < 0 || row >=m || col >= n) continue;
                if(!ocean[row][col] && heights[row][col] >= heights[p.first][p.second]){
                    ocean[row][col] = true;
                    q.push({row,col});
                }
                // cout<<row<<" "<<col<<" "<<ocean[row][col];
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        queue<pair<int,int>> pacq;
        queue<pair<int,int>> atlq;
        for(int i=0;i<m;i++){
            pac[i][0] = true;
            atl[i][n-1] =true;
            pacq.push({i,0});
            atlq.push({i,n-1});
        }

        for(int i=0;i<n;i++){
            pac[0][i] = true;
            atl[m-1][i] = true;
            pacq.push({0,i});
            atlq.push({m-1,i});
        }

        bfs(heights,pac,pacq);
        bfs(heights,atl,atlq);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};