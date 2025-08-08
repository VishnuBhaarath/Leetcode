class Solution {
public:
    int func(vector<int> prices,int i,int k,int buy,vector<vector<vector<int>>>dp){
        if(k==0){
            return 0;
        }
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }

        if(buy){
            return dp[i][k][0]=max((-prices[i]+func(prices,i+1,k,0,dp)),(0+func(prices,i+1,k,1,dp)));
        }
        else{
            return dp[i][k][1]=max((+prices[i]+func(prices,i+1,k-1,1,dp)),(0+func(prices,i+1,k,0,dp)));
        }
       
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>> (k+1,vector<int> (2,0)));
       for(int i=n-1;i>=0;i--){
        for(int j=1;j<=k;j++){
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

      return dp[0][k][1];

    }
};