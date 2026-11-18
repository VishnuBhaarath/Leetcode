class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(i!=j){
                    if(isConnected[i][j]==1)
                    adj[i+1].push_back(j+1);
                 }
            }
        }
        unordered_map<int,int> umap;
        int cnt=0;
        for(int i=1;i<=n;i++){
             if(umap[i]==0){
                cnt+=1;
                 queue<int> q;
                 q.push(i);
                 umap[i]+=1;
                 while(!q.empty()){
                     vector<int> v=adj[q.front()];
                     q.pop();
                     for(int j=0;j<v.size();j++){
                        if(umap[v[j]]==0){
                            q.push(v[j]);
                        }
                        umap[v[j]]+=1;
                     }
                 }
             }
        }
        return cnt;
    }
};