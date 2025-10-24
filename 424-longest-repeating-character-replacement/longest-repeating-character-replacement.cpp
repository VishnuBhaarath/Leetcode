class Solution {
public:
    int characterReplacement(string s, int k) {
        string s1=s;
        int ans=0;
        int k1=k;
        for(char ch='A';ch<='Z';ch++){
            int i=0;
            int j=0;
            int cnt=0;
           
            k=k1;
           
            while(j<s.size()){
              
                if(s[j]==ch){
                  
                    cnt+=1;
                }
                else{
                    if(k>0){
                        k-=1;
                        cnt+=1;
                    }
                    else{
                        while(s[i]==ch){
                           cnt-=1;
                           i+=1;
                        }
                        i+=1;
                        
                    }
                }
                j+=1;
                ans=max(ans,cnt);
                
            }
           
        }

        return ans;
    }
};