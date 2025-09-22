class Solution {
public:
   int func(int i, int sum1,int sum2,vector<int>& nums,vector<vector<int>> &dp){
    if(i==nums.size()){
        if(sum1==sum2){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][sum1]!=-1){
        return dp[i][sum1];
    }
    if(dp[i][sum2]!=-1){
        return dp[i][sum2];
    }
    int set1=func(i+1,sum1+nums[i],sum2,nums,dp);
    int set2=func(i+1,sum1,sum2+nums[i],nums,dp);
    dp[i][sum1]=set1||set2;
    dp[i][sum2]=set1||set2;
   
    return set1 || set2;
   }
    bool canPartition(vector<int>& nums) {
         int n=nums.size();
         int m=0;
         for(int i=0;i<nums.size();i++){
            m+=nums[i];
         }
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        
         return func(0,0,0,nums,dp);
    }
};