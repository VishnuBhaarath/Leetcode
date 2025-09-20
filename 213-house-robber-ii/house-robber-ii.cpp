class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        if(n==1){
            return nums[0];
        }
        dp[1]=nums[1];
        if(n>2){
        dp[2]=max(nums[2],dp[1]);
        for(int i=3;i<nums.size();i++){
            int val1=nums[i]+dp[i-2];
            int val2=dp[i-1];
            dp[i]=max(val1,val2);
        }
        }
        int ans=dp[n-1];
       
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<(n-1);i++){
            int val1=nums[i]+dp[i-2];
            int val2=dp[i-1];
            dp[i]=max(val1,val2);
        }
        
        ans=max(ans,dp[n-2]);
        return ans;
    }
};