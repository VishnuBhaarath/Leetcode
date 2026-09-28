class Solution {
public:
   vector<vector<int>> dp;
    int func(int i,int j,string s){
        if(j<=i){
            return 0;
        }   
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j]=func(i+1,j-1,s);
        }
        else{
            return dp[i][j]=1+min(func(i+1,j,s),func(i,j-1,s));
        }
    }

    int minInsertions(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
       // int cnt=func(i,j,s);
        return dp[0][n-1];
    }
};