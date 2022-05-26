class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum%2)!=0){
            return false;
        }
        int val=sum/2;
        vector<int> v(sum+1,0);
        vector<vector<int>> dp(n+1,v);
       
        for(int i=0;i<n;i++){
            dp[i+1][nums[i]]=1;
            if(nums[i]==val){
                return true;
            }
            for(int j=0;j<dp[0].size();j++){
                
                if(dp[i][j]==1){
                    dp[i+1][j]=1;
                    dp[i+1][j+nums[i]]=1;
                    if((j+nums[i])==val){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};