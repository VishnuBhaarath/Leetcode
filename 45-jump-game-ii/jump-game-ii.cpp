class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;


        for(int i=0;i<nums.size();i++){
            if(dp[i]!=-1){
                 int idx=i+nums[i];
                 int j=i+1;
                 idx=min(idx,n-1);
                 while(j<=idx){
                     if(dp[j]==-1){
                        dp[j]=dp[i]+1;
                     }
                     dp[j]=min(dp[j],dp[i]+1);
                     j+=1;
                 }
            }
        }
        return dp[n-1];
    }
};