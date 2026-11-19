class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,0);

        for(int i=0;i<graph.size();i++){
             queue<int> q;
             if(v[i]==0){
                q.push(i);
                v[i]=1;
                while(!q.empty()){
                     int tp=q.front();
                     q.pop();
                     vector<int> &v1=graph[tp];
                     int c=v[tp];
                     for(int j=0;j<v1.size();j++){
                        if(v[v1[j]]==c){
                            return false;
                        }
                        else if(v[v1[j]]==0){
                        if(c==1){
                            v[v1[j]]=-1;
                            q.push(v1[j]);
                        }
                        else{
                            v[v1[j]]=1;
                             q.push(v1[j]);
                        }
                        }
                     }
                }
             }
        }
        return true;
    }
};