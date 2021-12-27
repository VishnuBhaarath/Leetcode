class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0){
            return false;
        }
        int cnt=0;
        int idx=0;
        for(int i=0;i<locked.size();i++){
            if(locked[i]=='1'){
               
               if(s[i]==')'){
                    int val=i-cnt;
                    if(val<=0){
                        return false;
                    }
                    cnt+=1;
                }
                else{
                    cnt-=1;
                }
                cnt+=1;
            }
        }
        cnt=0;
        for(int i=locked.size()-1;i>=0;i--){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    int val=locked.size()-1-i-cnt;
                  
                    if(val<=0){
                        return false;
                    }
                    cnt+=1;
                 }
                else{
                    cnt-=1;
                }
                cnt+=1;
            }
        }
        return true;
    }
};