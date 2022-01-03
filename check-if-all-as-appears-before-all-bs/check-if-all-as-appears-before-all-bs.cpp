class Solution {
public:
    bool checkString(string s) {
        int t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                t=1;
            }
            else{
                if(t==1){
                    return false;
                }
            }
        }
        return true;
    }
};