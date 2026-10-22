class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n=s.size();
        int cnt=n;
        int cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                cnt1+=1;
            }
            else{
                if(cnt1>0){
                    cnt1-=1;
                    cnt-=2;
                }
            }
        }
       
        int q=cnt/2;
        int ans=q/2;
        if(q%2!=0){
            ans+=1;
        }
        return ans;
    }
};