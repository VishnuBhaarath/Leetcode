class Solution {
public:
      vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
        vector<int> v;
        v.push_back(0);
        traversal(graph,v,0);
        return ans;
    }
    void traversal(vector<vector<int>> graph,vector<int> v,int i){
        if(i==graph.size()-1){
            ans.push_back(v);
            return;
        }
        for(int j=0;j<graph[i].size();j++){
            v.push_back(graph[i][j]);
            traversal(graph,v,graph[i][j]);
            v.pop_back();
        }
        return;
    }
};