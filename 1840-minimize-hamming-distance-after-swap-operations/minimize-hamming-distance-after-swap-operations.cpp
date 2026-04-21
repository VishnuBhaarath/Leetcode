class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<vector<int>> v(n);
        for(int i=0;i<allowedSwaps.size();i++){
            v[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            v[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        
        vector<vector<int>> adj;
        map<int,int> umap;
        for(int i=0;i<v.size();i++){
            vector<int> v1;
            if(umap[i]==0){
                queue<int> q;
                umap[i]+=1;
                q.push(i);
                v1.push_back(i);
                while(!q.empty()){
                   int tp=q.front();
                   q.pop();
                   vector<int> v2=v[tp];
                   for(int j=0;j<v2.size();j++){
                       if(umap[v2[j]]==0){
                         umap[v2[j]]+=1;
                         q.push(v2[j]);
                         v1.push_back(v2[j]);
                       }
                   }
                }
            }
            adj.push_back(v1);
        }
        int ans=0;
        for(int i=0;i<adj.size();i++){
            map<int,int> umap;
            for(int j=0;j<adj[i].size();j++){
               
                umap[source[adj[i][j]]]+=1;
               
            }
            int cnt=0;
            for(int j=0;j<adj[i].size();j++){
                if(umap[target[adj[i][j]]]>0){
                    umap[target[adj[i][j]]]-=1;
                    cnt+=1;
                }
                
               
            }
            ans+=(adj[i].size()-cnt);

           
        }
        return ans;
    }
};