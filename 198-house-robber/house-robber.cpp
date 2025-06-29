class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        if(n==1){
            return nums[0];
        }
        dp[1]=nums[1];
        if(n==2){
            return max(nums[0],nums[1]);
        }
        dp[2]=nums[2]+dp[0];
        if(n==3){
            return max(dp[2],dp[1]);
        }
        dp[3]=max((nums[3]+dp[1]),(nums[3]+dp[0]));
        for(int i=3;i<nums.size();i++){
           dp[i]=max((nums[i]+dp[i-2]),(nums[i]+dp[i-3]));
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>ans){
                ans=dp[i];
            }
        }
        return ans;
    }
};