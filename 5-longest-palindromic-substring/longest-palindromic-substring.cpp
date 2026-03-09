class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int start = 0, maxLen = 1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                if(maxLen==1){
                    start = i;
                    maxLen = 2;
                }
            }
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        if(len>maxLen){
                            start = i;
                            maxLen = len;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};