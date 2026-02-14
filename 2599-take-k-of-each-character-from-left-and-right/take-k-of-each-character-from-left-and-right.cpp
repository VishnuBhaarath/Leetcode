class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0){
            return 0;
        }
        int cnt1,cnt2,cnt3;
        cnt1=cnt2=cnt3=0;
        int idx=-1;
        for(int i=0;i<s.size();i++){
             if(s[i]=='a'){
                cnt1+=1;
             }
             if(s[i]=='b'){
                cnt2+=1;
             }
             if(s[i]=='c'){
                cnt3+=1;
             }
             if(cnt1>=k && cnt2>=k && cnt3>=k){
                 idx=i;
                 break;
             }
        }
        if(idx==-1){
            return -1;
        }
        int i=idx;
       
        int ans=idx+1;
        int n=s.size();
        int j=n-1;
        while(i>=0 && j>=i){
             if(s[j]=='a'){
                cnt1+=1;
             }
             else if(s[j]=='b'){
                cnt2+=1;
             }
             else{
                cnt3+=1;
             }
          
             while(cnt1>=k && cnt2>=k && cnt3>=k){
               
                int sz=n-j;
             sz+=(i+1);
             ans=min(ans,sz);
             if(i<0){
                break;
             }
                 if(s[i]=='a'){
                    cnt1-=1;
                 }
                 else if(s[i]=='b'){
                    cnt2-=1;
                 }
                 else{
                    cnt3-=1;
                 }
                 i-=1;
                 
             }
            
             j-=1;
        }
        return ans;
    }
};