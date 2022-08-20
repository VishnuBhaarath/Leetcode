class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        map<int,int> umap2;
        map<int,vector<int>> umap1;
        for(int i=0;i<edges.size();i++){
            umap1[edges[i][0]].push_back(edges[i][1]);
            umap1[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<restricted.size();i++){
            umap2[restricted[i]]+=1;
        }
      
        int cnt=1;
    
           
                queue<int> q;
                q.push(0);
                umap2[0]+=1;
                while(!q.empty()){
                    vector<int> v=umap1[q.front()];
                    q.pop();
                    for(int j=0;j<v.size();j++){
                        if(umap2[v[j]]==0){
                            q.push(v[j]);
                            umap2[v[j]]+=1;
                            cnt+=1;
                        }
                    }
                }
            
            return cnt;
        
        return 4;
    }
};