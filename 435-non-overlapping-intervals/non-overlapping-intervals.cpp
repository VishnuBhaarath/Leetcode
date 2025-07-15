class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int i=1;
        int j=0;
        int cnt=0;
        while(i<intervals.size()){
            if(intervals[i][0]>=intervals[j][1]){
                j=i;
                i+=1;
            }
            else{
                if(intervals[i][1]<intervals[j][1]){
                    j=i;
                    i+=1;
                }
                else{
                    i+=1;
                }
                cnt+=1;
            }
        }
        return cnt;
    }
};