class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp(2000,0);

        for(int i=0;i<trips.size();i++){
             int l=trips[i][1];
             int r=trips[i][2];
             int cnt=trips[i][0];
             for(int j=l;j<r;j++){
                dp[j]+=cnt;
                if(dp[j]>capacity){
                    return false;
                }
             }
        }
      return true;
    }
};