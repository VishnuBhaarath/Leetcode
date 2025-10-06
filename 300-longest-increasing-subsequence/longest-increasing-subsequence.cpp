class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
                else{
                    dp[i]=max(dp[i],1);
                }
            }
        }
        
        return ans;
    }
};