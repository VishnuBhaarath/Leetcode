class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>> pq;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++){
             if(pq.empty()){
                 int x=points[i][1]-points[i][0];
                 pq.push({x,points[i][0]});
             }
             else{
                 while(abs(pq.top().second-points[i][0])>k){
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                 }
                 if(!pq.empty()){
                     int sum=pq.top().first + points[i][1]+points[i][0];
                     ans=max(ans,sum);
                 }
                  int x=points[i][1]-points[i][0];
                 pq.push({x,points[i][0]});
              
             }
        }

        return ans;
    }
};