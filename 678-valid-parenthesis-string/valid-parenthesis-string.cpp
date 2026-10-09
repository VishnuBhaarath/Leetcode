class Solution {
public:
    bool checkValidString(string s) {
        int cnt=0;
        int cnt1=0;
        int n=s.size();
        int t=0;
        stack<int> st1;
        stack<int> st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt+=1;
                st2.push(i);
            }
            else if(s[i]=='*'){
                cnt1+=1;
                st1.push(i);
            }
            else if(s[i]==')'){
                if(cnt>0){
                    st2.pop();
                    cnt-=1;
                }
                else if(cnt1>0){
                    st1.pop();
                    cnt1-=1;
                }
                else{
                    t=1;
                   break;
                }
            }
        }

      
        cout<<t;
        cout<<" ";
        cout<<cnt;
        if(cnt==0 && t==0){
            return true;
        }
        while(!st2.empty()){
            if(!st1.empty()){
                if(st1.top()>st2.top()){
                    st1.pop();
                    st2.pop();
                    cnt-=1;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        if(cnt==0 && t==0){
            return true;
        }
    
        int cnt2=0;
        int cnt3=0;
        for(int i=n-1;i>=0;i--){
             if(s[i]==')'){
                cnt2+=1;
            }
            else if(s[i]=='*'){
                cnt3+=1;
            }
            else if(s[i]=='('){
                if(cnt2>0){
                    cnt2-=1;
                }
                else if(cnt3>0){
                    cnt3-=1;
                }
                else{
                   return false;
                }
            }
        }
        
        if(cnt2==0){
            return true;
        }
        
        return false;

    }
};