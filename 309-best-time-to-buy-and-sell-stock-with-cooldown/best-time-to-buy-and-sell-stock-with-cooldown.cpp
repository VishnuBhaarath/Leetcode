class Solution {
public:
    vector<vector<int>> dp;
    int func(int i,int k,vector<int>& prices){
        
         if(i>=prices.size()){
            return 0;
         }
          if(dp[i][k]!=-1){
            return dp[i][k];
         }
         if(k==0){
            return dp[i][k]=max(-prices[i]+func(i+1,1,prices),func(i+1,0,prices));
         }
      
            return dp[i][k]=max(+prices[i]+func(i+2,0,prices),func(i+1,1,prices));
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int k=0;
        dp.resize(n,vector<int>(2,-1));
      

        return func(i,k,prices);
    }
};