class Solution {
public:
    int func(int amount,vector<int>& coins,int i,int cnt,vector<vector<int>> &dp){
        if(amount<0){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(i==coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        
        int nottake=func(amount,coins,i+1,cnt,dp);
        int take=func(amount-coins[i],coins,i,cnt,dp);
        dp[i][amount]=take+nottake;
        return take+nottake;
    }
     

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return func(amount,coins,0,0,dp);
    }
};