class Solution {
public:
    int minInsertions(string text1) {
         string text2=text1;
        reverse(text2.begin(),text2.end());

         int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return text1.size()-dp[n][m];
    }
};