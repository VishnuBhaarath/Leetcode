class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
       // set<int> s;
        for(int i=0;i<prerequisites.size();i++){
            v[prerequisites[i][0]]+=1;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                q.push(i);
                ans.push_back(i);
                cnt+=1;
              //  s.insert(i);
            }
        }
      
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            for(int i=0;i<adj[tp].size();i++){
                v[adj[tp][i]]-=1;
                if(v[adj[tp][i]]==0){
            ans.push_back(adj[tp][i]);
                        //s.insert(adj[tp][i]);
                        q.push(adj[tp][i]);
                    
                    cnt+=1;
                }
            }
        }
if(cnt==numCourses){
    return ans;
}
ans.clear();
        return ans;
    }
};