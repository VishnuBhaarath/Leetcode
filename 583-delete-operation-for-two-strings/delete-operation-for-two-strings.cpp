class Solution {
public:
    vector<vector<int>> dp;
    int func(string &word1, string &word2,int i, int j){
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
            return dp[i][j]=func(word1,word2,i+1,j+1);
        }
        else{
            return dp[i][j]=1+min(func(word1,word2,i+1,j),func(word1,word2,i,j+1));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.resize(n,vector<int>(m,-1));
        return func(word1,word2,0,0);
    }
};