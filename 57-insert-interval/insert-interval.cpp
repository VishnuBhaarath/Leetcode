class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l=newInterval[0];
        int r=newInterval[1];
        vector<vector<int>> ans;
        int idx=-1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<l){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else if(l<=intervals[i][1] && r>=intervals[i][0]){
                l=min(l,intervals[i][0]);
                r=max(r,intervals[i][1]);
            }
            else if(intervals[i][0]>r){
                idx=i;
                
                ans.push_back({l,r});
                break;
            }
        }
        if(idx==-1){
            ans.push_back({l,r});
        }
        for(int i=idx;i<intervals.size();i++){
            ans.push_back({intervals[i][0],intervals[i][1]});
        }

        return ans;

    }
};