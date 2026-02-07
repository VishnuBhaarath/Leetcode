class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
             v1[i]=cnt;
             if(s[i]=='a'){
                cnt+=1;
             }
        }
        cnt=0;
         int ans=-1;
        for(int i=0;i<n;i++){
            int val=v1[i]+cnt;
            if(ans==-1){
                ans=val;
            }
            else{
                ans=min(ans,val);
            }
            if(s[i]=='b'){
                cnt+=1;
            }
        }
       
        
        return ans;
    }
};