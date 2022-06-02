class Solution {
public:
    int longestValidParentheses(string s) {
         stack<int> st;
       int ans=0;
       for(int i=0;i<s.size();i++){
           if(st.empty()){
               st.push(i);
           }
           else{
               if(s[i]=='('){
                   st.push(i);
               }
               else{
                   if(s[st.top()]==')'){
                       st.push(i);
                   }
                   else{
                      int tp=st.top();
                      st.pop();
                      int val=i-tp+1;
                      if(st.empty()){
                          val+=tp;
                      }
                      else{
                          int tp1=st.top();
                          val+=tp-tp1-1;
                      }
                      ans=max(ans,val);
                   }
               }
           }
       }
       return ans;
        
    }
};