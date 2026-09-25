class Solution {
public:
    vector<string> ans;
    bool isvalid(string &s){
        stack<char> st;
        for(int j=0;j<s.size();j++){
            if(st.empty()){
                st.push(s[j]);
            }
            else if(s[j]=='('){
                st.push(s[j]);
            }
            else{
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
    void func(int i,int n,int cnt1,int cnt2,string s){
        if(cnt1==0 && cnt2==0){
            if(isvalid(s)){
                ans.push_back(s);
            }
           
        }

        if(cnt1>0){
            func(i+1,n,cnt1-1,cnt2,s+'(');
        }
        if(cnt2>0){
            func(i+1,n,cnt1,cnt2-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        int i=0;
        func(i,2*n,n,n,"");
        return ans;
    }
};