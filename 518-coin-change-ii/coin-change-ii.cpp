class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        sort(coins.begin(),coins.end());
        unsigned long long n=coins.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,0));
        
        for(long long int i=0;i<coins.size();i++){
           for(long long int j=0;j<=amount;j++){
                if(j<coins[i]){
                    dp[i+1][j]=dp[i][j];
                }
                else if(j==coins[i]){
                    dp[i+1][j]=dp[i][j]+1;
                }
                else{
                    if(i==0){
                       
                        if(j==(unsigned long long int)(coins[i])){
                            cout<<"in";
                            dp[i+1][j]=1;
                        }
                        else{
 dp[i+1][j]=dp[i][j]+dp[i+1][j-coins[i]];
                        }
                       
                    }
                    else{
                       
                        dp[i+1][j] = dp[i][j] + dp[i+1][j - coins[i]];}
                        
                    }
                
                   
                }
           }
        
        
        return dp[n][amount];
    }
};