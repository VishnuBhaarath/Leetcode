class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
       
        vector<vector<int>> dp;
        int start=points[0][0];
        int end=points[0][1];
        int cnt=0;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                dp.push_back({start,end});
                start=points[i][0];
                end=points[i][1];
                cnt+=1;
            }
            else{
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
        }
        dp.push_back({start,end});
        
        cnt+=1;
       
        return cnt;
    }
};