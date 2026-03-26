class Solution {
public:
    vector<vector<string>> ans;
    bool ischeck(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i+=1;
            j-=1;
        }
        return true;
    }
    void check(vector<string> v){
 int t=0;
        for(int i=0;i<v.size();i++){
            string st=v[i];
            int j=0;
            int k=st.size()-1;
           
            while(j<=k){
                 if(st[j]!=st[k]){
t=1;
break;
                 }
                 j+=1;
                 k-=1;
            }
            if(t==1){
                break;
            }
        }
        if(t==0){
            ans.push_back(v);
        }
    }
    void func(int i, string s,vector<string> v){
        if(i==s.size()){
           // check(v);
            ans.push_back(v);
            return;
        }
       
        string s1="";
        for(int j=i;j<s.size();j++){
           s1+=s[j];
           if(ischeck(s1)){
           v.push_back(s1);
           func(j+1,s,v);
           v.pop_back();}
          
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
         func(0,s,v);
         return ans;
    }
};