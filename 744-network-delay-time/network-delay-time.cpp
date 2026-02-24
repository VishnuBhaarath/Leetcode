class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> v(n+1,INT_MAX);
        vector<vector<int>> adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back(times[i][1]);
        }
        map<pair<int,int>,int> umap;
        for(int i=0;i<times.size();i++){
            umap[{times[i][0],times[i][1]}]=times[i][2];
        }
      priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        v[k]=0;
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int idx=p.second;
            int cost=p.first;
           
            for(int i=0;i<adj[idx].size();i++){
              
               if(umap[{idx,adj[idx][i]}]+cost < v[adj[idx][i]]){
                 v[adj[idx][i]]=umap[{idx,adj[idx][i]}]+cost;
                 pq.push({v[adj[idx][i]],adj[idx][i]});
               
               }
              
            }
           
        }
        int c=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==INT_MAX){
                return -1;
            }
            c=max(c,v[i]);

        }


        return c;
    }
};