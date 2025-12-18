class Solution {
public:
    vector<int> dp;
    vector<vector<int>> adj;
    vector<int> res;

    void dfs1(int u,int p,int sum,vector<int>&good){
        dp[u]=good[u];
        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]!=p){
                dfs1(adj[u][i],u,sum,good);
               
              
                dp[u]=max(dp[u],dp[u]+max(0,dp[adj[u][i]]));
           
            }
        }

        return;
    }

    void dfs2(int u,int p,int sum,vector<int> & good){
        res[u]=dp[u]+ max(0,sum);

        for(int i=0;i<adj[u].size();i++){
            if(adj[u][i]!=p){
                dfs2(adj[u][i],u,res[u]-max(0,dp[adj[u][i]]),good);
            }
        }
    return;
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        adj.resize(n);
        res.resize(n,0);
        dp.resize(n,0);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<good.size();i++){
            if(good[i]==0){
                good[i]=-1;
            }
            else{
                good[i]=1;
            }
        }
        dfs1(0,-1,0,good);
        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        dfs2(0,-1,-1,good);
        
        return res;
    }
};