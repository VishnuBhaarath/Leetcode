class Solution {
public:
    int zigZagArrays(int N, int L, int R) {
         const int MOD = 1e9 + 7;
        int M = R - L + 1;

        vector<vector<int>> dp(N, vector<int>(M, 0));
        // Initialize first row with 1s
        for (int i = 0; i < M; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < N; ++i) {
            long long s = 0;
            for (int j = 0; j < M; ++j)
                s = (s + dp[i - 1][j]) % MOD;

            if (i % 2 == 1) {
                long long sum = s;
                for (int v = M - 1; v >= 0; --v) {
                    sum = (sum - dp[i - 1][v] + MOD) % MOD;
                    dp[i][v] = sum;
                }
            } else {
                long long sum = s;
                for (int v = 0; v < M; ++v) {
                    sum = (sum - dp[i - 1][v] + MOD) % MOD;
                    dp[i][v] = sum;
                }
            }
        }

        long long result = 0;
        for (int v = 0; v < M; ++v) {
            result = (result + dp[N - 1][v]) % MOD;
        }

        return (result * 2) % MOD;
    }
};