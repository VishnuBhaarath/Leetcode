class Solution {
public:
    vector<int> delrow = {-1, 0, 1, 0}, delcol = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++) {
            int nrow = r + delrow[i], ncol = c + delcol[i]; 
            if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board); 
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(); 
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < m; i++) {
            // first row
            if(!vis[0][i] && board[0][i] == 'O') dfs(0, i, vis, board);
            //last row
            if(!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1, i, vis, board);
        }

        for(int i = 0; i < n; i++) {
            // first col
            if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board);
            // last col
            if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, vis, board);
        }

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        } 
    }
};