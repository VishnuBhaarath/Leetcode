class Solution {
public:
    vector<vector<string>> ans;
    map<string,int> umap;
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
  
    void func(int i, string s,vector<string> v){
        if(i==s.size()){
           // check(v);
            ans.push_back(v);
            return;
        }
       
        string s1="";
        for(int j=i;j<s.size();j++){
           s1+=s[j];
           if(umap[s1]==0){
              if(ischeck(s1)){
                 v.push_back(s1);
           func(j+1,s,v);
           v.pop_back();
           umap[s1]=1;
              }
              else{
                 umap[s1]=-1;
              }
           }
           else if(umap[s1]==1){
             v.push_back(s1);
           func(j+1,s,v);
           v.pop_back();
           }
           
          
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
         func(0,s,v);
         return ans;
    }
};