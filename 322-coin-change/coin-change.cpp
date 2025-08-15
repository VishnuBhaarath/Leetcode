class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v (amount+1,-1);
        if(amount==0){
            return 0;
        }
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=amount){
                v[coins[j]]=1;
                if(v[i]!=-1){
                    if(i+coins[j]<=amount){
                    v[i+coins[j]]=min(v[i]+1,v[i+coins[j]]);
                    if(v[i+coins[j]]==-1){
                        v[i+coins[j]]=v[i]+1;
                    }}
                }
            }
            }
        }
        
        return v[amount];
    }
};