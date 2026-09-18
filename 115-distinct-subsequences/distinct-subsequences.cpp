class Solution {
public:
//int cnt=0;
    vector<vector<int>> dp;
    int func(string s,int i,int j,string t){
        
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
       
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=func(s,i+1,j+1,t)+ func(s,i+1,j,t);
        }
        else{
            return dp[i][j]=func(s,i+1,j,t);
        }
     
        
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return func(s,0,0,t);
       // return cnt;
    }
};