class Solution {
public:
    long long smallestNumber(long long num) {
        string st=to_string(num);
        long long val=0;
        int cnt=0;
        for(int i=0;i<st.size();i++){
            if(st[i]=='0'){
                cnt+=1;
            }
        }
        if(cnt==st.size()){
            return 0;
        }
        if(st[0]=='-'){
            sort(st.begin(),st.end());
            string ans="";
            for(int i=st.size()-1;i>=0;i--){
                if(st[i]!='-'){
                    ans+=st[i];
                }
            }
            val=stoll(ans);
            val=val*-1;
            return val;
        }
        else{
            sort(st.begin(),st.end());
            if(cnt==0){
                string ans="";
                for(int i=0;i<st.size();i++){
                    ans+=st[i];
                }
                val=stoll(ans);
            }
            else{
                string ans="";
                ans+=st[cnt];
                for(int i=0;i<st.size();i++){
                    if(i!=cnt){
                        ans+=st[i];
                    }
                }
                val=stoll(ans);
            }
            
        }
        return val;
    }
};