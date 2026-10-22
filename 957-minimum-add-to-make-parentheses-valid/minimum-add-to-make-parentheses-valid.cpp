class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt+=1;
            }
            else{
                if(cnt>0){
                    cnt-=1;
                }
                else{
                    ans+=1;
                }
            }
        }
        
        return ans+cnt;
    }
};