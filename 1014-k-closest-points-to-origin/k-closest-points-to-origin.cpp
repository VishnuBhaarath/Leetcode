class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
             pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        vector<vector<int>> ans;
        int j=0;
        while(j<k){
           pair<int,int> p=pq.top();
           cout<<p.second;
           ans.push_back({points[p.second][0],points[p.second][1]});
            pq.pop();
            j+=1;
        }
        return ans;
    }
};