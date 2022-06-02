class Solution {
public:
    int longestValidParentheses(string s) {
       int ans=0;
       int left=0;
       int right=0;
        int n=s.size();
       for(int i=0;i<s.size();i++){
           if(s[i]=='('){
               left+=1;
           }
           if(s[i]==')'){
               right+=1;
           }
           if(left==right){
               ans=max(ans,2*left);
           }
           if(right>left){
               left=right=0;
               
           }
       } 
        left=right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                left+=1;
            }
            else{
                right+=1;
            }
            if(left==right){
                ans=max(ans,2*left);
            }
            if(left>right){
                left=right=0;
            }
        }
       
       return ans;
        
    }
};