class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if((sum%2)!=0){
            return false;
        }
        int n=nums.size();
        vector<int> v(sum+1,0);
        vector<vector<int>>dp(n+1,v);
        for(int i=1;i<dp.size();i++){
        
            for(int j=1;j<dp[0].size();j++){
             
                if(j>=nums[i-1]){
                
                if(dp[i-1][j-nums[i-1]]!=0){
                     
                    int val=j-nums[i-1];
                    if(val==(sum/2)){
                        return true;
                    }
                    dp[i][j]=1;
                }
                else{
                    if(j==nums[i-1]){
                        if(j==(sum/2)){
                            return true;
                        }
                        dp[i][j]=1;
                    }
                    
                }}
                
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
           
           
        }
       
        return false;
    }
};