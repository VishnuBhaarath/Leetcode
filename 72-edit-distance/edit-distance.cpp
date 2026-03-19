class Solution {
public:
    vector<vector<int>> dp;
    int func(string word1, string word2, int i, int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==word2.size() || i==word1.size()){
            if(i!=word1.size()){
                 return word1.size()-i;
            }
            if(j!=word2.size()){
                return word2.size()-j;
            }
            return 0;
        }

        if(word1[i]!=word2[j]){
            
            return dp[i][j]=1+min(min(func(word1,word2,i+1,j+1) ,func(word1,word2,i+1,j)),func(word1,word2,i,j+1));
        }

        return dp[i][j]=func(word1,word2,i+1,j+1);

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return func(word1,word2,0,0);
        
    }
};