class Solution {
public:
    
     

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0){
            return 1;
        }
        vector<vector<unsigned long long int>> dp(n+1,vector<unsigned long long int>(amount+1,0));
        for(int i=n-1;i>=0;i--){
            if(coins[i]<=amount){
            dp[i][coins[i]]=1;}
            for(int j=0;j<=amount;j++){

               dp[i][j]+=dp[i+1][j];
               if((j-coins[i])>=0){
                dp[i][j]+= dp[i][j-coins[i]];
               }
               
            }
        }
        
       
       
        return dp[0][amount];
    }
};