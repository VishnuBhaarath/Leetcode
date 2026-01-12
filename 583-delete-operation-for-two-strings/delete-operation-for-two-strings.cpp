class Solution {
public:

    int check(string word1,string word2,int i ,int j,vector<vector<int>> &dp){
        if(i==word1.size() && j==word2.size()){
            return 0;
        }
        if(i==word1.size() && j!=word2.size()){
            return word2.size()-j;
        }
        if(i!=word1.size() && j==word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]== word2[j]){
            return dp[i][j]=check(word1,word2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=min(1+check(word1,word2,i+1,j,dp),1+check(word1,word2,i,j+1,dp));
        }
return 0;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
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
        cout<<ans;
        cout<<word1.size();
        cout<<" ";
        cout<<word2.size();
        return word1.size()+word2.size()-ans-ans;
    }
};