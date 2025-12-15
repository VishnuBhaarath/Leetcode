class Solution {
public:
  int check(char s) {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
            return 1;
        }
        return 0;
    }
    string reverseWords(string s) {
         string s1="";
        
        int cnt=0;
        int cnt1=0;
        int t=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(t==0){
                s1+=s[i];
               if(s[i]==' '){
                
t=1;
               }
               else{ 
                if(check(s[i])){
                cnt+=1;
                }
              }
            }
            else{
                if(s[i]==' '){
                   
                    if(cnt1==cnt){
                        reverse(temp.begin(),temp.end());{
                            s1+=temp;
                        }
                    }
                    else{
                        s1+=temp;
                    }
                    s1+=s[i];
                    temp="";
                    cnt1=0;
                }
                else{
                 if(check(s[i])){
                cnt1+=1;
                }
                temp+=s[i];
                }
            }
        }
        if(cnt1==cnt){
                        reverse(temp.begin(),temp.end());{
                            s1+=temp;
                        }
                    }
                    else{
                        s1+=temp;
                    }
        return s1;
        
    }
};