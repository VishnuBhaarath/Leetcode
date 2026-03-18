class Solution {
public:
    int cnt=0;
    vector<vector<int>> dp;
    int func(string s, string t,int i,int j){
         
         if(j==t.size()){
            
           // cnt+=1;
            return 1;
         }
         if(i==s.size()){
            return 0;
         }
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
         if(s[i]==t[j]){
        return dp[i][j]=func(s,t,i+1,j+1)+func(s,t,i+1,j);}

         return dp[i][j]=func(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
         string st="";
         int n=s.size();
         int m=t.size();
         dp.resize(n,vector<int>(m,-1));
         int val= func(s,t,0,0);
        
         return dp[0][0];
    }
};