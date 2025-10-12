class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int cnt=numBottles;
        int fullbottles=0;
        int emptybottles=numBottles;
        while(1){
            if(fullbottles>0){
                cnt+=fullbottles;
                emptybottles+=fullbottles;
                fullbottles=0;

            }
            else{
                if(emptybottles<numExchange){
                    return cnt;
                }
                else{
                    fullbottles+=1;
                    emptybottles-=numExchange;
                    numExchange+=1;

                }
            }
        }
        return cnt;
    }
};