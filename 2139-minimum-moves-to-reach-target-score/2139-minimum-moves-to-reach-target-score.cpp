class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        int i=0;
        if(target==1){
            return 0;
        }
        while(i<maxDoubles){
            if((target%2)==0){
                target=target/2;
                cnt+=1;
                i+=1;
            }
            else{
                target-=1;
                cnt+=1;
            }
            if(target==1){
                return cnt;
            }
        }
        if(target>=1){
            cnt+=target-1;
            return cnt;
        }
        return 1;
    }
};