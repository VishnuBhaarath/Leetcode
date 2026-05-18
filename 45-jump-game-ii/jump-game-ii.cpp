class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
             if(dp[i]==-1){
                return -1;
             }
             else{
                 int r=i+nums[i];
                 r=min(r,n-1);
                 int j=i+1;
                 while(j<=r){
                     if(dp[j]==-1){
                        dp[j]=1+dp[i];
                     }
                     else{
                        dp[j]=min(dp[j],1+dp[i]);
                     }
                     j+=1;
                 }
             }
        }
        return dp[n-1];
    }
};