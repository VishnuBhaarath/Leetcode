class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        if(amount==0){
            return 0;
        }
        dp[0]=1;
        for(int i=0;i<=amount;i++){
            if(dp[i]!=0){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=amount){
                long long int k=(long long)(i+coins[j]);
                if(k<=amount){
                    if(dp[k]==0){
                        dp[k]=1+dp[i];
                        if(i==0){
                            dp[k]=1;
                        }
                    }
                    dp[k]=min(dp[k],1+dp[i]);
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