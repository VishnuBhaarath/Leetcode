class Solution {
public:
    bool isValid(string s) {
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                s[j]=s[i];
                j+=1;
            }
            else{
                if(s[i]==')'){
                    if(j-1<0){
                        return false;
                    }
                    if(s[j-1]!='('){
                        return false;
                    }
                    else{
                        j-=1;
                    }
                }
                if(s[i]==']'){
                     if(j-1<0){
                        return false;
                    }
                    if(s[j-1]!='['){
                        return false;
                    }
                    else{
                        j-=1;
                    }
                }
                if(s[i]=='}'){
                     if(j-1<0){
                        return false;
                    }
                    if(s[j-1]!='{'){
                        return false;
                    }
                    else{
                       j-=1;
                    }
                }
            }
        }
        if(j!=0){
            return false;
        }
        return true;
    }
};