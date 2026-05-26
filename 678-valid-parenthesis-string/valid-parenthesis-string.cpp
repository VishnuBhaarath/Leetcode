class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;
        stack<int> s2;

        for(int i=0;i<s.size();i++){
             if(s[i]=='('){
                s1.push(i);
             }
             else if(s[i]=='*'){
                s2.push(i);
             }
             else{
                if(s1.empty() && s2.empty()){
                    return false;
                }
                else if(!s1.empty()){
                    s1.pop();
                }
                else if(!s2.empty()){
                    s2.pop();
                }
             }
        }

        if(s1.empty()){
            return true;
        }
        if(!s1.empty() && s2.empty()){
            return false;
        }
        while(!s1.empty()){
            if(s2.empty()){
                return false;
            }
            int tp=s1.top();
            s1.pop();
            int tp1=s2.top();
            s2.pop();
            if(tp1<tp){
                return false;
            }
            
        }

        return true;
    }
};