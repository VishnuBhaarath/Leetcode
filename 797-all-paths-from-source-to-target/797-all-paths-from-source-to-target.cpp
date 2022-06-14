class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<vector<int>>& graph, int node, int dest, vector<int> v)
    {
        if(node == dest){
            ans.push_back(v);
        return;}
        
        
        for(int i=0; i<graph[node].size(); i++)
        {
            v.push_back(graph[node][i]);
            backtrack(graph, graph[node][i], dest, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         int dest = graph.size() - 1;
        vector<int> v;
        v.push_back(0);
        backtrack(graph, 0, dest, v);
        return ans;
    }
};