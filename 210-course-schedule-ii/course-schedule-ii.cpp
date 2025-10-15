class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(numCourses);
          vector<int> v(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
             v[prerequisites[i][1]]+=1;
        }

      
        
        queue<int> q;
        vector<int> ans(numCourses,0);
        int idx=numCourses-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
            q.push(i);
           
            }
        }
   
        int cnt=0;
        while(!q.empty()){
           
            int tp=q.front();
            ans[idx]=tp;
            idx-=1;
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
            return ans;
            //return true;
        }
        vector<int> v1;
        return v1;
        
    }
};