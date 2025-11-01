class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
            }
            else{
                cnt+=1;
                end=min(end,intervals[i][1]);
            }
        }
        return cnt;
    }
};