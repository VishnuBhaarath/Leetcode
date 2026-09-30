class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int temp=k;
        for(char ch='A';ch<='Z';ch++){
            int i=0;
            int j=0;
            k=temp;
            int t=0;
            while(j<s.size()){
                if(s[j]==ch){
                    int sz=(j-i+1);
                    ans=max(ans,sz);
                    j+=1;
                }
                else{
                    if(k>0){
                        int sz=(j-i+1);
                        ans=max(ans,sz);
                        k-=1;
                        j+=1;
                    }
                    else{
                        while(1){
                            if(s[i]!=ch){
                                i+=1;
                                break;
                            }
                            i+=1;
                            if(i>j){
                                
                                break;
                            }
                        }
                       
                        int sz=(j-i+1);
                        ans=max(ans,sz);
                        j+=1;
                    }
                }
               
            }
           
        }
        return ans;
    }
};