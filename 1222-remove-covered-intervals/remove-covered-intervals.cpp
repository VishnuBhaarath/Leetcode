class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=intervals.size();
        int l=intervals[0][0];
        int r=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]==l){
                cnt-=1;
                r=max(r,intervals[i][1]);
            }
            else{
                if(intervals[i][1]<=r){
                    cnt-=1;
                }
                else{
                    r=max(r,intervals[i][1]);
                    l=max(l,intervals[i][0]);
                }
            }
        }
        
        return cnt;
    }
};