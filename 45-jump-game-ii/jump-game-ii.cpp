class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            if(j==n){
                break;
            }
            int k=nums[i];
            while(k>0){
                if(dp[j]==-1){
                    dp[j]=1+dp[i];
                }
                else{
                    dp[j]=min(dp[j],1+dp[i]);
                }
                j+=1;
                if(j==n){
                    break;
                }
                k-=1;
            }
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        return dp[n-1];
    }
};