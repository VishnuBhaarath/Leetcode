class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int>& prices,int i,int buy,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            return dp[i][buy]=max(-prices[i]+func(prices,i+1,0,n), func(prices,i+1,1,n));
        }
        else{
          return dp[i][buy]=max(+prices[i]+func(prices,i+2,1,n),func(prices,i+1,0,n));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return func(prices,0,1,n);
    }
};