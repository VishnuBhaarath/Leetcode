class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                if(st.empty()){
                    st.push(i);
                }
                else{
                    if(s[i]=='('){
                        st.push(i);
                    }
                    else{
                        if(s[st.top()]=='('){
                            st.pop();
                        }
                        else{
                            st.push(i);
                        }
                    }
                }
            }
        }
        vector<int> v(n,0);
        while(!st.empty()){
            v[st.top()]+=1;
            st.pop();
        }
        string s1;
        for(int i=0;i<s.size();i++){
            if(v[i]==0){
                s1+=s[i];
            }
        }


        return s1;
    }
};