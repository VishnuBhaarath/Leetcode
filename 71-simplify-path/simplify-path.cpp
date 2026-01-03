class Solution {
public:
    string simplifyPath(string path) {
        string finalpath = "";
        stack<string> st;
        vector<string> result;
        string temp;

        for (char c : path) {
            if (c == '/') {
                if (!temp.empty())
                    result.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        if (!temp.empty())
            result.push_back(temp);

        for(int i=0;i<result.size();i++){
            cout<<result[i];
            cout<<" ";
            if(result[i]!="."){
                if(st.empty()){
                    if(result[i]!="..")
                    st.push(result[i]);
                }
                else {
                if(result[i]==".."){
                    if(!st.empty()){
                    st.pop();}
                }
                else{
                    st.push(result[i]);
                }
                }
            }
        }   
        cout<<"\n";
        vector<string> ans;
        while(!st.empty()){
            cout<<st.top();
            ans.push_back(st.top());
            cout<<"\n";
            st.pop();
        } 
        string s="";
        s+="/";
        reverse(ans.begin(),ans.end());
         
        for(int i=0;i<ans.size();i++){
            s+=ans[i];
            if(i==ans.size()-1){
                return s;
            }
            s+="/";
        }
        return s;
    }
};