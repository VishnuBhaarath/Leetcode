class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]!=']'){
                    st.push(s[i]);
                }
                else{
                    string temp="";
                    while(st.top()!='['){
                        temp+=st.top();
                        st.pop();
                    }
                    st.pop();
                    cout<<temp;
                    reverse(temp.begin(),temp.end());
                    cout<<" ";
                    string temp1="";
                    while(!st.empty()){
                        if(isdigit(st.top())){
                             temp1+=st.top();
                             st.pop();
                        }
                        else{
                            break;
                        }
                    }
                    reverse(temp1.begin(),temp1.end());
                    int len=stoi(temp1);
                    string temp2="";
                    for(int j=0;j<len;j++){
                        temp2+=temp;
                    }
                    for(int j=0;j<temp2.size();j++){
                        st.push(temp2[j]);
                    }
                    //st.push(temp2);
                    cout<<temp1;
                    cout<<" ";
                    cout<<temp2;
                    cout<<"\n";
                }
            }
           
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};