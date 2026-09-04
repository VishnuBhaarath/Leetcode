class Solution {
public:
  vector<vector<vector<int>>> dp;
  int func(int i, vector<int>& prices, int buy, int cap,int n){
      if(i==n){
        return 0;
      }
      if(cap==0){
        return 0;
      }
      
      if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
      }
      if(buy){
        return dp[i][buy][cap]=max(-prices[i]+func(i+1,prices,0,cap,n), func(i+1,prices,1,cap,n));
      }
      else{
        return  dp[i][buy][cap]=max(prices[i]+func(i+1,prices,1,cap-1,n), func(i+1,prices,0,cap,n));
      }
  }
   
   int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

      
       dp.resize(n,vector<vector<int>>(2,vector<int> (3,-1)));
        

        return func(0,prices,1,2,prices.size());
    }
};