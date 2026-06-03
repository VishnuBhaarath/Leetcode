class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> v(n+1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            v[edges[i][1]]+=1;
            v[edges[i][0]]+=1;
        }
         queue<int> q;
         vector<int> visited(n+1,0);
         for(int i=0;i<v.size();i++){
            if(v[i]<=1){
                q.push(i);
                visited[i]=1;
            }
        }

        while(!q.empty()){
            int u=q.front();
            v[u]-=1;
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                v[adj[u][i]]-=1;
               if(v[adj[u][i]] <= 1 && visited[adj[u][i]] == 0) {
                    q.push(adj[u][i]);
                    visited[adj[u][i]]=1;
                }

            }
        }
        
       for(int i=0;i<v.size();i++){
         if(v[i]>1){
            cout<<i;
            cout<<"\n";
         }
       }
       for(int j=edges.size()-1;j>=0;j--){
          int u=edges[j][0];
          int w=edges[j][1];

          if(v[u]>1 && v[w]>1){
            return {u,w};
          }
       }
return {};
    }
   
};