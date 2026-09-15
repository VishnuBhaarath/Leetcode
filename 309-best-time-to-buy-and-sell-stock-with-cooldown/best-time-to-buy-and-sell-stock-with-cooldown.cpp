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
        dp.resize(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
        if(buy==1){
             dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        }
        else{
            dp[i][buy]=max(+prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        }}

        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return dp[0][1];
    }
};