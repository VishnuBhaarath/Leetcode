class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
            if(s.empty()){
                s.push(num[i]);
            }
            else{
                if(s.top()-'0'<= num[i]-'0'){
                    s.push(num[i]);
                }
                else if(k>0){
                    while(s.top()-'0' > num[i]-'0'){
                        s.pop();
                        k-=1;
                        if(s.empty()){
                            break;
                        }
                        if(k==0){
                            break;
                        }
                    }
                    s.push(num[i]);
                }
                else{
                    s.push(num[i]);
                }

            }
        }
     
        string ans="";
        while(k>0){
            s.pop();
            k-=1;
            if(s.empty()){
                break;
            }
        }
        while(!s.empty()){
            ans+=s.top();
            s.pop();
                    }
                    reverse(ans.begin(),ans.end());

        string ans1="";
        for(int i=0;i<ans.size();i++){
            if(ans1.size()==0){
                if(ans[i]!='0'){
                    ans1+=ans[i];
                }
            }
            else{
                ans1+=ans[i];
            }
        }
        if(ans1.size()==0){
            return "0";
        }
        return ans1;
    }
};