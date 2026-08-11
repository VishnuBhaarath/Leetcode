class Solution {
public:
    int characterReplacement(string s, int k) {
        int temp=k;
        int ans=0;
        for(char ch='A';ch<='Z';ch++){
            int i=0;
            int j=0;
           
            k=temp;
           
            while(j<s.size()){
                if(s[j]!=ch){
                    if(k>0){
                        k-=1;
                    }
                    else{
                        while(s[i]==ch){
                            i+=1;
                        }
                        i+=1;
                        k=0;
                    }

                }
                j+=1;
               
                ans=max(ans,(j-i));
                

            }
           
        }
        return ans;
    }
};