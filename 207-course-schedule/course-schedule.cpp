class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
             v[prerequisites[i][0]]+=1;
             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(v[i]==0){
                q.push(i);
                cnt+=1;
            }
        }
        while(!q.empty()){
             int tp=q.front();
             q.pop();
             vector<int> v1=adj[tp];
             for(int i=0;i<v1.size();i++){
                v[v1[i]]-=1;
                if(v[v1[i]]==0){
                    cnt+=1;
                    q.push(v1[i]);
                }
             }
        }
        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};