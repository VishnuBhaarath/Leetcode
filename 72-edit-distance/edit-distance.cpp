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
        dp.resize(n+1,vector<int>(m+1,0));
        for(int j=0;j<dp[0].size();j++){
             dp[n][j]=word2.size()-j;
        }
        for(int i=0;i<dp.size();i++){
             dp[i][m]=word1.size()-i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                 if(word1[i]==word2[j]){
                     dp[i][j]=dp[i+1][j+1];
                 }
                 else{
                    dp[i][j]=1+min(min(dp[i+1][j+1],dp[i+1][j]),dp[i][j+1]);
                 }
            }
        }

        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return dp[0][0];
        
    }
};