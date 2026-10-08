class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        int end = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                cnt += 1;
                end = intervals[i][1];
            }
            else{
                end=min(end,intervals[i][1]);
            }
        }
        return n-cnt;
    }
};