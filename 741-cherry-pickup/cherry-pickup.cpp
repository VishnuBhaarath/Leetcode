class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> memo;
    const int NEG = INT_MIN / 2;

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= m || r2 >= n || c2 >= m || c2 < 0) return NEG;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return NEG;
        if (r1 == n - 1 && c1 == m - 1) return grid[r1][c1];

        int &res = memo[r1][c1][r2];
        if (res != -2) return res;   // -2 = not computed

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];

        int best = max({
            solve(r1 + 1, c1, r2 + 1, grid),  // down, down
            solve(r1 + 1, c1, r2,     grid),  // down, right
            solve(r1,     c1 + 1, r2 + 1, grid), // right, down
            solve(r1,     c1 + 1, r2,     grid)  // right, right
        });

        if (best <= NEG) return res = NEG;
        return res = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, vector<int>(n, -2)));
        int ans = solve(0, 0, 0, grid);
        return ans < 0 ? 0 : ans;
    }
};