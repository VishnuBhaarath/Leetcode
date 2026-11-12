class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            
                 if(nums[i]>nums[i-1]){
                    dp[i]=max(dp[i],dp[i-1]+1);
                    ans=max(ans,dp[i]);
                 }
            
        }
        vector<int> dp1(n,1);
        for(int i=n-2;i>=0;i--){
            
                if(nums[i+1]<nums[i]){
                    dp1[i]=max(dp1[i],dp1[i+1]+1);
                    ans=max(ans,dp1[i]);
                }
            
        }

        return ans;
    }
};