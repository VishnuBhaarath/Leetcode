class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    if(st.top()=='['){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }
       
        int q=st.size()/2;
        int ans=q/2;
        if(q%2!=0){
            ans+=1;
        }
        return ans;
    }
};