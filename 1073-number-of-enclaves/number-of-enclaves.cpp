class Solution {
public:
    vector<int> v1 = {-1, 1, 0, 0}; vector<int> v2 = {0, 0, -1, 1}; 
    void solve(
        vector<vector<int>> & grid, vector<vector<int>>& vis, int i, int j) {
            int n=grid.size();
            int m=grid[0].size();
           
           vis[i][j] = 1;

        for (int k = 0; k < v1.size(); k++) {
            int r = i + v1[k];
            int c = j + v2[k];
           

            if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1 && vis[r][c]==0) {
                
                solve(grid, vis, r, c);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (vis[i][0] == 0 && grid[i][0] == 1) {
                solve(grid, vis, i, 0);
            }

            if (vis[i][m - 1] == 0 && grid[i][m - 1] == 1) {
                solve(grid, vis, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (vis[0][j] == 0 && grid[0][j] == 1) {
                solve(grid, vis, 0, j);
            }

            if (vis[n - 1][j] == 0 && grid[n - 1][j] == 1) {
                solve(grid, vis, n - 1, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (vis[i][j] == 0) {
                        cnt += 1;
                    }
                }
            }
        }
        return cnt;
    }
};