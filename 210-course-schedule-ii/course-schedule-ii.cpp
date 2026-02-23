class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v(numCourses,0);
        vector<int> ans;
        map<int,vector<int>> umap;
        for(int i=0;i<prerequisites.size();i++){
            v[prerequisites[i][0]]+=1;
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        int cnt=q.size();
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            vector<int> v1=umap[tp];
            for(int j=0;j<v1.size();j++){
                v[v1[j]]-=1;
                if(v[v1[j]]==0){
                    q.push(v1[j]);
                    ans.push_back(v1[j]);
                    cnt+=1;
                }
            }
        }
        if(cnt!=numCourses){
            ans.clear();
        }
        
        return ans;
    }
};