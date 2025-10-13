class Solution {
public:
     void bfs(vector<vector<int>>& adj,vector<bool>& visited,int i){
        visited[i]=true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int currentNode=q.front();
            q.pop();
            for(int adjNode:adj[currentNode]){
                if(!visited[adjNode]){
                    visited[adjNode]=true;
                    q.push(adjNode);
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                bfs(adj,visited,i);
            }
        }
        return ans;
    }
};