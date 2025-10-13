class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<edges.size();i++){
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }
        if(source==destination){
            return true;
        }
        queue<int> q;
        q.push(source);
        map<int,int> umap1;
        umap1[source]=1;
        while(!q.empty()){
             vector<int> v=umap[q.front()];
             q.pop();
             for(int i=0;i<v.size();i++){
                if(v[i]==destination){
                    return true;
                }
                if(umap1[v[i]]==0){
                    q.push(v[i]);
                    umap1[v[i]]+=1;
                }
             }
        }

        return false;
    }
};