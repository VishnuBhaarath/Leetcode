class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int func(int i, int j, int rows, int cols, int moves) {
        if (moves < 0) return 0;
        if (i < 0 || i >= rows || j < 0 || j >= cols) return 1;
        if (dp[i][j][moves] != -1) return dp[i][j][moves];

        long long res = 0;
        res += func(i + 1, j, rows, cols, moves - 1);
        res += func(i - 1, j, rows, cols, moves - 1);
        res += func(i, j + 1, rows, cols, moves - 1);
        res += func(i, j - 1, rows, cols, moves - 1);
        return dp[i][j][moves] = res % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return func(startRow, startColumn, m, n, maxMove);
    }
};