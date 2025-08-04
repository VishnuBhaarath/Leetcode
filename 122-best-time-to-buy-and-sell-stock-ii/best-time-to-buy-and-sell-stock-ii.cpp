class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int i=1;
        int sum=0;
        while(i<prices.size()){
            if(buy==-1){
                buy=prices[i];
            }
            else if(prices[i]<=buy){
                buy=prices[i];
            }
            else{
                if((i+1)<prices.size()){
                    if(prices[i+1]<prices[i]){
                         sum+=(prices[i]-buy);
                         buy=-1;
                    }
                }
                else{
                    sum+=(prices[i]-buy);
                }
            }
            i+=1;
        }
        return sum;
    }
};