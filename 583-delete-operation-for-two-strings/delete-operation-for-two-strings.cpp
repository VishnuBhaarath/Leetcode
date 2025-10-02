class Solution {
public:
    int func(string &word1, string &word2, int i,int j,vector<vector<int>>dp){
        if(i==word1.size() && j==word2.size()){
            return 0;
        }
        if(i==word1.size()){
            return word2.size()-j;
        }
        if(j==word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]=func(word1,word2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=1+min(func(word1,word2,i+1,j,dp),func(word1,word2,i,j+1,dp));
        }
        return 0;
    }
    
    int minDistance(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       int ans=0;
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=0;i<word1.size();i++){
        for(int j=0;j<word2.size();j++){
            if(word1[i]==word2[j]){
              dp[i+1][j+1]=1+dp[i][j];
              ans=max(ans,dp[i+1][j+1]);
            }
            else{
              dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
              ans=max(ans,dp[i+1][j+1]);
            }
        }
       }
 
     
       return n+m-(2*ans);
    }
};