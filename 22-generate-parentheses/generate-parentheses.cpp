class Solution {
public:
    vector<string> ans;
    int check(string s){
         stack<char> st;
         for(int i=0;i<s.size();i++){
            if(st.empty() || s[i]=='('){
                st.push(s[i]);
            }
            else{
                int tp=st.top();
                if(tp=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
         }
         if(st.empty()){
            return 1;
         }
         return 0;
    }
    void func(int m,int n,int open ,string s){
        if(m==0 && n==0){
          
            ans.push_back(s);
           
           return;
        }
        if(m>0){
            s+='(';
            func(m-1,n,open+1,s);
            s.pop_back();

        }
        if(n>0 && open>0){
            s+=')';
            func(m,n-1,open-1,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0;
        func(n,n,0,s);
        return ans;
        
    }
};