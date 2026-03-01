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
        dp[1]=max(dp[0],nums[1]);
        ans=max(ans,dp[1]);
        for(int i=2;i<nums.size()-1;i++){
             dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
             ans=max(ans,dp[i]);
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        cout<<"\n";

        vector<int> dp1(n,0);
        
        dp1[1]=nums[1];
        ans=max(ans,dp1[1]);
        if(n==2){
            return ans;
        }
        dp1[2]=max(dp1[1],nums[2]);
        ans=max(ans,dp1[2]);
        for(int i=3;i<nums.size();i++){

             dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
             ans=max(ans,dp1[i]);
        }


          for(int i=0;i<dp1.size();i++){
            cout<<dp1[i];
            cout<<" ";
        }
        cout<<"\n";
        return ans;
        
    }
};