class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        for(int i=0;i<coins.size();i++){
             if(coins[i]<=amount){
                dp[coins[i]]=1;
                if(coins[i]==amount){
                    return 1;
                }
             }
        }
        if(amount==0){
            return 0;
        }
         for(int i=1;i<dp.size();i++){
          
             if(dp[i]!=0){
                for(int j=0;j<coins.size();j++){
                      if(((long long int)(i)+(long long int)(coins[j]))<=(long long int) amount){
                         if(dp[i+coins[j]]==0){
                             dp[i+coins[j]]=dp[i]+1;
                         }
                         else{
                            dp[i+coins[j]]=min(dp[i]+1,dp[i+coins[j]]);
                         }
                      }
                }
             }
            
         }
       

       if(dp[amount]==0){
        return -1;
       }

       return dp[amount];
    }
};