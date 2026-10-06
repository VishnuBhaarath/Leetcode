class Solution {
public:
    int minAddToMakeValid(string s) {
       int ans=0;
       int cnt=0;
       for(int i=0;i<s.size();i++){
         if(s[i]==')'){
            if(cnt<=0){
                ans+=1;
            }
            else{
                cnt-=1;
            }
         }
         else if(s[i]=='('){
            cnt+=1;
         }
       }
       return ans+cnt;
        
    }
};