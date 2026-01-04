class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int ans=1;
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
              if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
              }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};