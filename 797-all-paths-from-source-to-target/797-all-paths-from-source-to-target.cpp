class Solution {
public:
      vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
        vector<int> v;
        v.push_back(0);
        int dest=graph.size()-1;
        traversal(graph,v,0,dest);
        return ans;
    }
    void traversal(vector<vector<int>> graph,vector<int> v,int i,int dest){
        if(i==dest){
            ans.push_back(v);
            return;
        }
        for(int j=0;j<graph[i].size();j++){
            v.push_back(graph[i][j]);
            traversal(graph,v,graph[i][j],dest);
            v.pop_back();
        }
        return;
    }
};