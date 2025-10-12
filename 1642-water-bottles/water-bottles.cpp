class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles;
        while(1){
            int r=numBottles%numExchange;
            int q=numBottles/numExchange;
            cnt+=q;
            numBottles=q+r;
            if(q==0){
                return cnt;
            }
        }
        return cnt;
    }
};