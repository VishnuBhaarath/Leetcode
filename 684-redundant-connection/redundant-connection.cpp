class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> v(n+1,0);
vector<int> v1(n+1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            v[edges[i][0]]+=1;
            v[edges[i][1]]+=1;
        }
        queue<int> q;
        
        for(int i=1;i<v.size();i++){
            if(v[i]<=1){
q.push(i);
v1[i]+=1;
            }
        }

        while(!q.empty()){
            int tp=q.front();
            q.pop();
            v[tp]-=1;
            vector<int> v2=adj[tp];
            for(int i=0;i<v2.size();i++){
                 v[v2[i]]-=1;
                 if(v[v2[i]]<=1 && v1[v2[i]]==0){
                    v1[v2[i]]=1;
                    q.push(v2[i]);
                 }
            }

        }
        vector<int> ans;
        for(int i=edges.size()-1;i>=0;i--){
            int x=edges[i][0];
            int y=edges[i][1];
            if(v[x]>1 && v[y]>1){
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
        }
        return ans;
    }
};