class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> umap;
        for(int i=0;i<times.size();i++){
            umap[times[i][0]].push_back({times[i][1],times[i][2]});
        }
   priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
   vector<int> ans(n+1,INT_MAX);
   
   ans[k]=0;
   pq.push({0,k});
   while(!pq.empty()){
      pair<int,int> tp=pq.top();
      pq.pop();
      vector<pair<int,int>> v=umap[tp.second];
      
      for(int i=0;i<v.size();i++){
          if(ans[tp.second]+v[i].second < ans[v[i].first]){
            ans[v[i].first]=ans[tp.second]+v[i].second;
            pq.push({ans[v[i].first],v[i].first});
          }
      }

   }
   int val=ans[1];
   if(val==INT_MAX){
    return -1;
   }
   for(int i=2;i<ans.size();i++){
    if(ans[i]==INT_MAX){
        return -1;
    }
    if(ans[i]>val){
        val=ans[i];
    }
   
   }

     return val;

    }
};