class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &pathvisited, int i){
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]==0){
                visited[adj[i][j]]=1;
                pathvisited[adj[i][j]]=1;
                if(dfs(adj,visited,pathvisited,adj[i][j])==true){
                    return true;
                }
            }
            else{
                if(pathvisited[adj[i][j]]==1){
                    return true;
                }
            }
        }

        pathvisited[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<graph.size();i++){
          for(int j=0;j<graph[i].size();j++){
             adj[i].push_back(graph[i][j]);
          }
        }
       
        vector<int> ans;
        
        for(int i=0;i<n;i++){
              vector<int> visited(n,0);
              vector<int> pathvisited(n,0);
                visited[i]=1;
                pathvisited[i]=1;
               
                if(!dfs(adj,visited,pathvisited,i)){
                    ans.push_back(i);
                }
              

               
                pathvisited[i]=0;
            
        }
return ans;
    }
};