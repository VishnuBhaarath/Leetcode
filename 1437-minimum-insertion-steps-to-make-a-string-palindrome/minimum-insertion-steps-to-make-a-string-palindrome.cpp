class Solution {
public:
    vector<vector<int>> dp;
    int func(string &s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=func(s,i+1,j-1);
        }
        else{
            return dp[i][j]=1+min(func(s,i+1,j),func(s,i,j-1));
        }


    }
    int minInsertions(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        int i=0;
        int j=n-1;
        return func(s,i,j);
    }
};