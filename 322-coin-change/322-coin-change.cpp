class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<long long int> dp(amount+1,-1);
        if(amount==0){
            return 0;
        }
        if(amount<coins[0]){
            return -1;
        }
        for(int i=0;i<coins.size();i++){
            if(coins[i]>amount){
                break;
            }
            dp[coins[i]]=1;
        }
      
        for(int i=coins[0]+1;i<dp.size();i++){
            int min=-1;
          
            if(dp[i]==-1){
                for(int j=0;j<coins.size();j++){
                    if(coins[j]>=i){
                        break;
                    }
                    int temp1=i-coins[j];
                 
                   
                    if(dp[temp1]!=-1){
                        int val=dp[temp1]+1;
                      
                        if(min==-1){
                            min=val;
                        }
                        else if(val<min){
                            min=val;
                        }
                    }
                  
                }
        
                dp[i]=min;
            }
          
            
        }
       
        return dp[amount];
    }
};