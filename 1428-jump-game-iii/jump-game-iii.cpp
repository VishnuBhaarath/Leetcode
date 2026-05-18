class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<arr.size();i++){
             int l=i-arr[i];
             int r=i+arr[i];
             if(l>=0){
                adj[i].push_back(l);
             }
             if(r<n){
                adj[i].push_back(r);
             }
        }

        if(arr[start]==0){
            return true;
        }
        set<int> s;
        s.insert(start);
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int tp=q.front();
            q.pop();
            if(arr[tp]==0){
                return true;
            }
            for(int i=0;i<adj[tp].size();i++){
                 int idx=adj[tp][i];
                 if(arr[idx]==0){
                    return true;
                 }
                 if(s.count(idx)==0){
                    s.insert(idx);
                    q.push(idx);
                 }
            }
        }
        return false;
    }
};