class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int ans=0;
        dp[0]=nums[0];
        ans=dp[0];
        if(n==1){
            return dp[0];
        }
        dp[1]=max(dp[0],nums[1]);
        ans=max(ans,dp[1]);
        for(int i=2;i<nums.size();i++){
           int sum=0;
           for(int j=i-2;j>=0;j--){
              int val=dp[j]+nums[i];
              if(val>sum){
                sum=val;
              }
           }
           dp[i]=max(dp[i-1],sum);
        }
       
        return dp[n-1];
    }
};