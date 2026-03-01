class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        
        dp[0]=nums[0];
        int ans=dp[0];
        if(n==1){
            return ans;
        }
        dp[1]=nums[1];
        ans=max(ans,dp[1]);
        for(int i=2;i<nums.size();i++){
             dp[i]=dp[i-1];
            
             for(int j=i-2;j>=0;j--){
                 dp[i]=max(dp[i],nums[i]+dp[j]);
                 ans=max(ans,dp[i]);
             }
        }

        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        return ans;
    }
};