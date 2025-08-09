class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        sort(coins.begin(),coins.end());
        if(amount==0){
            return 0;
        }
        vector<int> v(amount+1,0);
        for(int i=0;i<coins.size();i++){
            if(coins[i]>amount){
                break;
            }
            v[coins[i]]=1;
            for(int j=0;j<v.size();j++){
                if(v[j]!=0){
                    if((j+coins[i])<=amount){
                    if(v[j+coins[i]]==0){
                        v[j+coins[i]]=v[j]+1;
                    }
                    else{
                        v[j+coins[i]]=min(v[j+coins[i]],v[j]+1);
                    }}
                }
            }
        }
       
        if(v[amount]==0){
            return -1;
        }
        return v[amount];
    }
};