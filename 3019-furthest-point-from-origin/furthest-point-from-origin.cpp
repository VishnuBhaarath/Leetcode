class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int cnt=0;
        int cnt1=0;
        for(int i=0;i<moves.size();i++){
             if(moves[i]=='L'){
                cnt+=1;
             }
             else if(moves[i]=='R'){
                cnt-=1;
             }
             else{
                cnt1+=1;
             }
        }
        if(cnt>0){
            return cnt+cnt1;
        }
        else{
            return abs(cnt-cnt1);
        }
        return 0;
    }
};