class Solution {
public:
    vector<vector<vector<int>>> dp;
    int func(vector<int>& prices,int i,int buy,int k,int n){
       
        if(i==n){
            return 0;
        }
         if(k==2){
            return 0;
        }
 if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }
        if(buy){
            return dp[i][k][buy]=max(-prices[i]+func(prices,i+1,0,k,n), func(prices,i+1,1,k,n));
        }
        else{
            return dp[i][k][buy]=max(+prices[i]+func(prices,i+1,1,k+1,n),func(prices,i+1,0,k,n));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp1(2,vector<int>(2,-1));
        dp.resize(n,dp1);
        return func(prices,0,1,0,n);
    }
};