class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lp(n,0);
        int len=0;
        int i=1;
        string temp="";
        int ans=0;
        while(i<n){
            if(s[i]==s[len]){
                len+=1;
                lp[i]=len;
                
                i++;
            }
            else{
                if(len!=0){
                    len=lp[len-1];
                }
                else{
               
                    i++;
                }
            }
        }
        int sz=lp[n-1];
        if(sz==0){
            return temp;
        }
        else{
            temp=s.substr(n-sz,sz);
        }
        return temp;
    }
};