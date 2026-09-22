class Solution {
public:
    int cnt=0;
    vector<vector<int>> dp;
    int func(int amount,vector<int>&coins,int i,int sum){
        
        if(sum==amount){
           return 1;
        }
       
        if(i==coins.size()){
            return 0;
        }
        if(sum>amount){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        return dp[i][sum]=func(amount,coins,i,sum+coins[i]) + func(amount,coins,i+1,sum);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return func(amount,coins,0,0);
       // return cnt;
    }
};