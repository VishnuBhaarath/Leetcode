class Solution {
public:
    int cnt=0;
    int func(vector<int>& nums, long long int target, long long int sum,int i,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(target==sum){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][sum+1000]!=-1){
            return dp[i][sum+1000];
        }
        return dp[i][sum+1000]=func(nums,target,sum+nums[i],i+1,dp)+func(nums,target,sum-nums[i],i+1,dp);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (2002,-1));
       
        return func(nums,target,0,0,dp);
        
    }
};