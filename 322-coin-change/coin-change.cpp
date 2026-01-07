class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount==0){
            return 0;
        }
        vector<int> dp(amount+1,0);
        for(int i=0;i<coins.size();i++){
            if(coins[i]<dp.size()){
                dp[coins[i]]=1;
            }
        }
        for(int i=1;i<dp.size();i++){
            for(int j=0;j<coins.size();j++){
                if(dp[i]>0){
                    if((long long)(i)+(long long)(coins[j]) <= (long long)(amount)){
                        if(dp[i+coins[j]]==0){
                            dp[i+coins[j]]=dp[i]+1;
                        }
                        else{
                            dp[i+coins[j]]=min(dp[i+coins[j]],dp[i]+1);
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