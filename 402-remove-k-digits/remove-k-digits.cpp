class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            if (st.empty()) {
                if(num[i]=='0'){
                    continue;
                }
                st.push(num[i]);
            }
            else if (num[i] >= st.top()) {
                st.push(num[i]);
            } else {
                if (k > 0) {
                    while (num[i] < st.top()) {
                        st.pop();
                        k -= 1;
                        if (st.empty()) {
                            break;
                        }
                        if(k==0){
                            break;
                        }
                    }
                    if(st.empty()){
                      if(num[i]!='0'){
                        st.push(num[i]);
                      }
                    }
                    else{
                    st.push(num[i]);}
                } else {
                    st.push(num[i]);
                }
            }
           
        }
        while(k>0){
            if(st.empty()){
                k=0;
                break;
            }
            st.pop();
            k-=1;
        }
        string ans="";
        while(!st.empty()){
          
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            ans+='0';
        }
        

        return ans;
    }
};