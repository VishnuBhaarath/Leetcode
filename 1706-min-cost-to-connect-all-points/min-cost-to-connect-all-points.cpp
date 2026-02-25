class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
               adj[i].push_back({dist, j});
               adj[j].push_back({dist, i});

            }
        }
        //int n=points.size();
        vector<int> v(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
             pair<int,int> p=pq.top();
             pq.pop();
             int cost=p.first;
             int idx=p.second;
            
             if(v[idx]==1){
                continue;
             }
             v[idx]=1;
             ans+=cost;
             for(auto x:adj[idx]){
                 pair<int,int> p1=x;
                 
                 if(v[p1.second]==0){
                    pq.push({p1.first,p1.second});
                 }
               
             }
        }
          
        return ans;

       

    }
};