class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,0);
        if(amount==0){
            return 0;
        }
        dp[0]=1;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i){
                    break;
                }
                if(i==coins[j]){
                    dp[i]=1;
                    break;
                }
                else{
                    if(dp[i-coins[j]]>0){
                        if(dp[i]==0){
                            dp[i]=dp[i-coins[j]]+1;
                        }
                        else{
                            dp[i]=min(dp[i],dp[i-coins[j]]+1);
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