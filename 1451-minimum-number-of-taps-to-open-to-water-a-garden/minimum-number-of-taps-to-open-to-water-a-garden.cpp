class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<vector<int>> dp;

        for (int i = 0; i < ranges.size(); i++) {
            int st = max(0, (i - ranges[i]));
            int end = min(n, (i + ranges[i]));
            if (st != end) {
                dp.push_back({st, end});
            }
        }

        sort(dp.begin(), dp.end());
        if(dp.size()==0){
            return -1;
        }
        if (dp[0][0] != 0) {
            return -1;
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i][0];
            cout<<" ";
            cout<<dp[i][1];
            cout<<"\n";
        }
        int i = 1;
        int cnt = 1;
        int st = dp[0][0];
        int end = dp[0][1];
        int end1=-1;
        while (i < dp.size()) {
        
            if (dp[i][0] == st) {
                end = max(end, dp[i][1]);
                if (end == n) {
                    return cnt;
                }
                i+=1;
            }
            else if(dp[i][0]<=end){
                end1=max(end1,dp[i][1]);
                if(end1==n){
                    return cnt+1;
                }
                i+=1;
            }
            else{
                if(end>=end1){
                    return -1;
                }
                end=end1;
                cnt+=1;
                continue;
            }

            
        }
        if(end1!=n){
            return -1;
        }
        

        return 1;
    }
};