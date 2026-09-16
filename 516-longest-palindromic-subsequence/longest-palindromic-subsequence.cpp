class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s1.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                int idx=n-1-j;
                if(s[i]==s[j]){
                    
                    dp[i+1][idx+1]=1+dp[i][idx];
                }
                else{
                    dp[i+1][idx+1]=max(dp[i+1][idx],dp[i][idx+1]);
                }
            }
        }
        return dp[n][n];
    }
};