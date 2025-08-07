class Solution {
public:
    int func(vector<int> prices, int buy, int capacity,int i, vector<vector<vector<int>>> dp){
        if(capacity==0){
            return 0;
        }
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][capacity][buy]!=-1){
            return dp[i][capacity][buy];
        }
 
       if(buy){
         return  dp[i][capacity][buy]= max((-prices[i]+ func(prices,0,capacity,i+1,dp)),(0+func(prices,1,capacity,i+1,dp)));
       }
       else{
        return dp[i][capacity][buy] =max((prices[i]+func(prices,1,capacity-1,i+1,dp)),(0+func(prices,0,capacity,i+1,dp)));
       }

    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (2,0)));
      // int val=func(prices,1,2,0,dp);

    
       for(int i=n-1;i>=0;i--){
        for(int j=1;j<3;j++){
            for(int k=0;k<2;k++){
               
                 if(k){
         dp[i][j][k]= max((-prices[i]+ dp[i+1][j][0]),(0+ dp[i+1][j][1]));
       }
       else{
        dp[i][j][k] =max((prices[i]+dp[i+1][j-1][1]),(0+dp[i+1][j][0]));
       }

                 
            }
        }
       }


      
      
       return dp[0][2][1];
    }
};