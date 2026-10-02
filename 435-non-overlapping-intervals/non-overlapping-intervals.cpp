class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         auto cmp = [&](const vector<int>& a, const vector<int>& b){
            
            return a[1] < b[1];  
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                cnt+=1;
            }
            else{
                end=intervals[i][1];
            }
        }
        return cnt;

    }
};