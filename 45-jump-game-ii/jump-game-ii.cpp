class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
             if(dp[i]!=-1){
             int k=min(n-1,i+nums[i]);
             for(int j=i+1;j<=k;j++){
                 if(dp[j]==-1){
                    dp[j]=1+dp[i];
                 }
                 else{
                    dp[j]=min(dp[j],1+dp[i]);
                 }
             }
             
             }

        }
        return dp[n-1];
    }
};