class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=(i*nums[i]);

        }
      

        dp[0]=ans;
ans=max(ans,dp[0]);
        for(int i=1;i<nums.size();i++){
            dp[i]=dp[i-1]+sum-n*nums[n-i];
            ans=max(ans,dp[i]);
        }
        
            
        
        
        return ans;
    }
};