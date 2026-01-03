class Solution {
public:
    bool check(int i, vector<int> & nums, int sum1,int sum2){
        if(i==nums.size()){
            if(sum1==sum2){
                return true;
            }
            return false;
        }
        return check(i+1,nums,nums[i]+sum1,sum2) || check(i+1,nums,sum1,sum2+nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2 !=0){
           return false;
        }
        int val=sum/2;
       
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(nums[i]==val){
                  
                     return true;
                }
                if(i==0){
                    dp[i][nums[i]]=1;
                    
                }
                else{
                    dp[i][nums[i]]=1;
                    if(dp[i-1][j]==1){
                        dp[i][j]=1;
                    }
                    if(j+nums[i]<=sum){
                        
                        if(dp[i-1][j]==1){
                            if((j+nums[i])==val){
                           return true;
                        }
                            dp[i][j+nums[i]]=1;
                        }
                    }
                }
            }
        }
        
        return false;
      // return check(0,nums,0,0);
    }
};