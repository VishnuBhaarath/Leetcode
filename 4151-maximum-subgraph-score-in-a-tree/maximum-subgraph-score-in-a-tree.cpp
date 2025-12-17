class Solution {
public:
  vector<vector<int>> adj;
    vector<int> dp, res;

    void dfs1(int u, int p, vector<int>& good) {
        dp[u] = good[u];

        for(int& v : adj[u]) {
            if(v != p) {
                dfs1(v, u, good);
                dp[u] += max(0, dp[v]);
            }
        }
        return;
    }

    void dfs2(int u, int p, int sum) {
        res[u] = dp[u] + max(0, sum);

        for(int& v : adj[u])
            if(v != p)
                dfs2(v, u, res[u] - max(0, dp[v]));
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        adj.resize(n); dp.resize(n); res.resize(n);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int& g : good)
            g = g ? 1 : -1;

        dfs1(0, -1, good);
        dfs2(0, -1, 0);

        return res;
    }
};