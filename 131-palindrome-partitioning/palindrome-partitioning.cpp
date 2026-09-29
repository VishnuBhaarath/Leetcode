class Solution {
public:
vector<vector<string>> ans;
    int check(string s){
       
         int i=0;
         int j=s.size()-1;
         while(i<=j){
            if(s[i]!=s[j]){
                return 0;
            }
            i+=1;
            j-=1;
         }
         return 1;
    }
    void func(int i,int n,string s,vector<string> v){
       
        if(i==n){
            ans.push_back(v);
            return;
        }

        string st="";
        for(int j=i;j<s.size();j++){
            st+=s[j];
            if(check(st)){
                v.push_back(st);
                func(j+1,n,s,v);
                v.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {

        int n=s.size();
        vector<string> v;
        func(0,n,s,v);
        return ans;



    }
};