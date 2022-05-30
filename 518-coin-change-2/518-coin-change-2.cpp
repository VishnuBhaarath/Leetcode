class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,0);
        if(amount==0){
            return 1;
        }
         for(int i=0;i<coins.size();i++){
             for(int j=0;j<dp.size();j++){
                 if(j+coins[i]>=dp.size()){
                     break;
                 }
                 if(j==0){
                     dp[coins[i]]+=1;
                 }
                 else{
                     dp[coins[i]+j]=dp[coins[i]+j]+dp[j];
                 }
             }
         }
        return dp[amount];
    }
};