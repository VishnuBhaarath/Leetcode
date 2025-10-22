class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            if (st.empty()) {
                st.push(num[i]);
            }
            else if (num[i] >= st.top()) {
                st.push(num[i]);
            } else {
                if (k > 0) {
                    while (num[i] < st.top()) {
                        st.pop();
                        k -= 1;
                        if (st.empty()) {
                            break;
                        }
                        if(k==0){
                            break;
                        }
                    }
                    st.push(num[i]);
                } else {
                    st.push(num[i]);
                }
            }
            cout<<num[i];
            cout<<" ";
            cout<<k;
            cout<<" ";
            cout<<st.size();
            cout<<"\n";
        }
        while(k>0){
            st.pop();
            k-=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int j=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                j=i;
                break;
            }
        }
        string s="";
        for(int i=j;i<ans.size();i++){
            s+=ans[i];
        }
        if(s.size()==0){
            s+='0';
        }
        

        return s;
    }
};