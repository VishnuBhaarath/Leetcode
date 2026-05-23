class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st1,st2;

        for(int i=0;i<s.size();i++){
             if(s[i]=='('){
                st1.push(i);
             }
             else if(s[i]=='*'){
                st2.push(i);
             }
             else{
                if(st1.empty() && st2.empty()){
                    return false;
                }
                else if(st1.size()!=0){
                    st1.pop();
                }
                else{
                    st2.pop();
                }
             }
        }
        if(st1.size()==0){
            return true;
        }
        if(st1.size()!=0 && st2.size()==0){
            return false;
        }
        if(st1.top()>st2.top()){
            return false;
        }

        while(!st1.empty()){
             if(st1.top()<st2.top()){
                st1.pop();
                st2.pop();
             }
             else{
                return false;
             }
             if(st1.empty()){
                return true;
             }
             if(st2.empty()){
                return false;
             }
        }
        return true;
    }
};