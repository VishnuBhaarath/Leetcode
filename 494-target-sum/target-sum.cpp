class Solution {
public:
    //int cnt=0;
    vector<vector<int>> dp;
    int func(vector<int>& nums,int target,int sum,int i){
         if(i==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
         }
         if(dp[i][sum+20000]!=-1){
            return dp[i][sum+20000];
         }
         return dp[i][sum+20000]=func(nums,target,sum+nums[i],i+1)+func(nums,target,sum-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int> (100000,-1));
        return func(nums,target,0,0);
        //return cnt;
    }
};