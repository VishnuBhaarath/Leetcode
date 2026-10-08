class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>end){
                v.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
        }
        v.push_back({start,end});
        return v;
    }
};