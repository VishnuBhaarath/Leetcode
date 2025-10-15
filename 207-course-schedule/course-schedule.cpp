class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
          vector<int> v(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
             v[prerequisites[i][1]]+=1;
        }

      
        
        queue<int> q;
        
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
            q.push(i);}
        }
        int cnt=0;
        while(!q.empty()){
           
            int tp=q.front();
            q.pop();
            cnt+=1;
            for(int i=0;i<adj[tp].size();i++){
                v[adj[tp][i]]-=1;
                if(v[adj[tp][i]] == 0){
                    q.push(adj[tp][i]);
                }
            }
            
           
            
        }
        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};