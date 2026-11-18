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
     //   unordered_map<int,int> umap;
        vector<int> v1(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
             if(v1[i]==0){
                cnt+=1;
                 queue<int> q;
                 q.push(i);
                 v1[i]+=1;
                 while(!q.empty()){
                     vector<int> v=adj[q.front()];
                     q.pop();
                     for(int j=0;j<v.size();j++){
                        if(v1[v[j]]==0){
                            q.push(v[j]);
                        }
                        v1[v[j]]+=1;
                     }
                 }
             }
        }
        return cnt;
    }
};