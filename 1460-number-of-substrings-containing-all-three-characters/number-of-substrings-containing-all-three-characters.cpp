class Solution {
public:
    int numberOfSubstrings(string s) {
        int cntA=0;
        int cntB=0;
        int cntC=0;
        int cnt=0;
        int j=0;
        int i=0;
        int n=s.size();
        while(j<n){
            if(s[j]=='a'){
                cntA+=1;
            }
            if(s[j]=='b'){
                cntB+=1;
            }
            if(s[j]=='c'){
                cntC+=1;
            }
            while(cntA>=1 && cntB>=1 && cntC>=1){
                cout<<i;
                cout<<" ";
                cout<<j;
                cout<<" ";
                cnt+=(n-j);
                cout<<"\n";

                if(s[i]=='a'){
                    cntA-=1;
                }
                if(s[i]=='b'){
                    cntB-=1;
                }
                if(s[i]=='c'){
                    cntC-=1;
                }
                i+=1;
            }
            j+=1;
        }
        return cnt;
    }
};