class Solution {
public:
    bool checkString(string s) {
        int t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
              if(t==1){
                return false;
              }
            }
            else{
                t=1;
            }
        }
        return true;
    }
};