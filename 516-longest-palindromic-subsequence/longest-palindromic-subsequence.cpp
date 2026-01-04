class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[i]==s1[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    ans=max(ans,dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return ans;
    }
};