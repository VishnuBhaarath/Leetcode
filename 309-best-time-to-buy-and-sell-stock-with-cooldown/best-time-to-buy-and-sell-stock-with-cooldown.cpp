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
        dp.resize(n+2,vector<int>(2,0));

         for (int i = n - 1; i >= 0; i--) {
        // Step 4: Copy recurrence exactly, func(...) → dp[...]
        
        // k=0 means: currently NOT holding stock
        dp[i][0] = max(-prices[i] + dp[i+1][1],  // buy
                        dp[i+1][0]);               // skip
        
        // k=1 means: currently HOLDING stock
        dp[i][1] = max(+prices[i] + dp[i+2][0],  // sell (cooldown=i+2!)
                        dp[i+1][1]);               // skip
    }

        return dp[0][0]; //func(i,k,prices);
    }
};