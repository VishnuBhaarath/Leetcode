class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
           if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
           }
           else{
            if(st.empty()){
                return false;
            }
            int tp=st.top();
            st.pop();
            if(s[i]==')'){
                if(tp!='('){
                    return false;
                }
            }
            if(s[i]==']'){
                if(tp!='['){
                    return false;
                }
            }
            if(s[i]=='}'){
                if(tp!='{'){
                    return false;
                }
            }
           }
        }
         if(!st.empty()){
            return false;
         }
        return true;
    }
};