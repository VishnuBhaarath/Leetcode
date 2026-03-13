class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy=prices[0];
        int sell=-1;
        for(int i=1;i<prices.size();i++){
            if(sell==-1){
             if(prices[i]<=buy){
                 buy=prices[i];
             }
             else{
                sell=prices[i];
             }
            }
            else{
                if(prices[i]>=sell){
                    sell=prices[i];
                }
                else{
                    ans+=(sell-buy);
                    buy=prices[i];
                    sell=-1;
                }
            }

        }
        if(sell!=-1){
            ans+=(sell-buy);
        }
        return ans;
    }
};