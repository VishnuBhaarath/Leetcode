class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> dp;
        int start=newInterval[0];
        int end=newInterval[1];
        int n=intervals.size();
        int t=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<start){
                dp.push_back({intervals[i][0],intervals[i][1]});
              
            }
            else if(intervals[i][0]>end){
                if(t==0){
                dp.push_back({start,end});}
                t=1;
                dp.push_back({intervals[i][0],intervals[i][1]});
            }
            else {
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
                if(i==n-1){
                    dp.push_back({start,end});
                    t=1;
                }
            }

        }
        if(t==0){
            dp.push_back({start,end});
        }
        return dp;
    }
};