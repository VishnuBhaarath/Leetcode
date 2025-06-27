class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=-1;
        int sum=0;
        for(int i=0;i<prices.size();i++){
            if(buy==-1){
                buy=prices[i];
            }
            else if(prices[i]<buy){
                buy=prices[i];
            }
            else{
                if((i+1)<prices.size()){
                    if(prices[i]> prices[i+1]){
                       sum+=prices[i]-buy;
                        buy=-1;
                    }
                }
                else{
                    sum+=prices[i]-buy;
                }
            }
        }
        return sum;
    }
};