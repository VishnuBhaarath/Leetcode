class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> dp;
        int start=newInterval[0];
        int end=newInterval[1];
        int n=intervals.size();
        int t=0;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<start){
            dp.push_back({intervals[i][0],intervals[i][1]});
            i+=1;
        }
        while(i<intervals.size() && intervals[i][0]<=end){
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i+=1;
        }
        dp.push_back({start,end});

         while(i<intervals.size() && intervals[i][0]>end){
            dp.push_back({intervals[i][0],intervals[i][1]});
            i+=1;
         }
        return dp;
    }
};