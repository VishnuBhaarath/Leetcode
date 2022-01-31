class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        long long int hash=0;
        long long int mod=pow(10,9)+7;
        for(int i=0;i<b.size();i++){
            hash=(hash*10+(b[i]-'a'+1))%mod;
        }
       
        string s=a;
        int i=0;
        int j=0;
        long long int curr=0;
        long long int pk=1;
        long long int cnt=1;
        while(1){
         
            curr=(curr*10+(s[i]-'a'+1))%mod;
            if((i-j+1)<=b.size()){
                pk=pk*10%mod;
            }
            else{
               
               curr = (curr - ((s[j] - 'a' + 1) * pk )% mod + mod) % mod;
                j+=1;
            }
            i+=1;
             if(curr==hash){
                if(s.substr(j,b.size())==b){
                    return cnt;
                } 
                break;
            }
            if(i==s.size()){
                
                if(s.size()>(2*b.size())){
                    if(cnt>10){
                    break;}
                }
                cnt+=1;
                s+=a;
            }
          
           
        }
        return -1;
    }
};