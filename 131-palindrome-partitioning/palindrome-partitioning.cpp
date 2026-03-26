class Solution {
public:
    vector<vector<string>> ans;
         vector<vector<int>> dp;
  
  
    void func(int i, string s,vector<string> v){
        if(i==s.size()){
           // check(v);
            ans.push_back(v);
            return;
        }
       
        string s1="";
        for(int j=i;j<s.size();j++){
           s1+=s[j];
           if(dp[i][j]==1){
 v.push_back(s1);
           func(j+1,s,v);
           v.pop_back();
           }
          
          
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        int n=s.size();
    dp.resize(n,vector<int>(n,0));

        for(int i = n-1; i >= 0; i--){        // go bottom-up
    for(int j = i; j < n; j++){
        if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))
            dp[i][j] = 1;
    }
}
         func(0,s,v);
         return ans;
    }
};