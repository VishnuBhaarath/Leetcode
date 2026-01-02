class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int tp=s.top();
                s.pop();
                int tp1=s.top();
                s.pop();
               
                s.push(tp+tp1);

            }
            else if(tokens[i]=="-"){
                int tp=s.top();
                s.pop();
                int tp1=s.top();
                s.pop();
                 
                s.push(tp1-tp);
            }
            else if(tokens[i]=="*"){
                int tp=s.top();
                s.pop();
                int tp1=s.top();
                s.pop();
                  
                s.push(tp*tp1);

            }
            else if(tokens[i]=="/"){
               int tp=s.top();
                s.pop();
                int tp1=s.top();
                s.pop();
                 
                s.push(tp1/tp);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};