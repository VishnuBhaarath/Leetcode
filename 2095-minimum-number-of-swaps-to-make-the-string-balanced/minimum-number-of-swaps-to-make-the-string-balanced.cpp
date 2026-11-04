class Solution {
public:
    int minSwaps(string s) {
        int val=INT_MAX;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                cnt+=1;
            }
            else{
                cnt-=1;
                val=min(val,cnt);
            }
        }
        int val1=abs(val);
        int ans=val1/2;
        if(val1%2!=0){
            ans+=1;
        }
        return ans;
    }
};