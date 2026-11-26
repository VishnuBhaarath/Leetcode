class Solution {
public:
    bool canAliceWin(int n) {
        int st=10;
        int t=0;
        while(1){
            if(n>=st){
                n-=st;
                if(t==0){
                    t=1;
                }
                else{
                    t=0;
                }
                st-=1;
            }
            else{
                if(t==1){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
};