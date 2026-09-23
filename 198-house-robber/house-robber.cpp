class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);

        dp[0]=nums[0];
        if(n==1){
            return dp[0];
        }
        dp[1]=max(nums[1],nums[0]);
        int ans=max(dp[0],dp[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};