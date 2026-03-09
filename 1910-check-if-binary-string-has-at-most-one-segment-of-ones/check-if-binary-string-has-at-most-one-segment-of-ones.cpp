class Solution {
public:
    bool checkOnesSegment(string s) {
        int t=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
t=1;

            }
            if(s[i]=='1'){
                if(t==1){
                    return false;
                }
            }
        }
         return true;
    }
   
};