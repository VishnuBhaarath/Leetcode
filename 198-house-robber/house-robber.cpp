class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        if(n==1){
            return nums[0];
        }
        dp[1]=max(dp[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int val1=nums[i]+dp[i-2];
            int val2=dp[i-1];
            dp[i]=max(val1,val2);
        }
        return dp[n-1];
    }
};