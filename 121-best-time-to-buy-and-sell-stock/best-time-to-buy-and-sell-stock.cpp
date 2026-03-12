class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy=-1;
        for(int i=0;i<prices.size();i++){
             if(buy==-1){
                buy=prices[i];
             }
             else{
                 if(prices[i]<=buy){
                    buy=prices[i];
                 }
                 else{
                    int val=prices[i]-buy;
                    ans=max(ans,val);
                 }
             }
        }
        return ans;
    }
};