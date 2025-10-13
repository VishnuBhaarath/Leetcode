class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    umap[i].push_back(j);
                }
            }
        }
        int n=isConnected.size();
        vector<int> v(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                v[i]+=1;
                cnt+=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    vector<int> v1= umap[q.front()];
                    q.pop();
                    for(int j=0;j<v1.size();j++){
                        if(v[v1[j]]==0){
                            v[v1[j]]+=1;
                            q.push(v1[j]);
                        }
                    }
                }

            }
        }
        return cnt;
    }
};