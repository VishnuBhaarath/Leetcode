class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n,0);
       
        dp[0]=costs[0]+1;
        if(n==1){
            return dp[0];
        }
        dp[1]=costs[1]+1+dp[0];
        dp[1]=min(dp[1],(costs[1]+4));
        if(n==2){
            return dp[1];
        }
        dp[2]=costs[2]+min((dp[0]+4),(dp[1]+1));
        dp[2]=min(dp[2],(costs[2]+9));
        if(n==3){
            return dp[2];
        }
        for(int i=3;i<costs.size();i++){
         int val1=costs[i]+dp[i-3]+9;
           int val2=costs[i]+dp[i-2]+4;
          int val3=costs[i]+dp[i-1]+1;
            dp[i]=val1;
            dp[i]=min(dp[i],val2);
            dp[i]=min(dp[i],val3);
        }
       
        return dp[n-1];
    }
};