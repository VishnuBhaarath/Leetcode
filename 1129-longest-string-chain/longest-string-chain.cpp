class Solution {
public:
    int check(string& word1, string& word2){
        int n=word1.size();
        int m=word2.size();
        if(n+1!=m){
            return 0;
        }
        int i=0;
        int j=0;
        while(i<n){
            if(word1[i]==word2[j]){
                i+=1;
                j+=1;
            }
            else{
                j+=1;
            }
            if(j==m && i==n){
                return 1;
            }
            if(i==n && j!=m){
                return 1;
            }
            if(j==m){
                break;
            }
            
        }
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<vector<string>> dp(17);
        for(int i=0;i<words.size();i++){
            dp[words[i].size()].push_back(words[i]);
        }

        for(int i=0;i<dp.size();i++){
            cout<<i;
            cout<<" ";
            for(int j=0;j<dp[i].size();j++){
                cout<<dp[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        int ans=1;
        vector<vector<int>> dp1(17,vector<int>(n+1,1));

        for(int i=2;i<dp.size();i++){
             for(int j=0;j<dp[i].size();j++){
                 string word1=dp[i][j];

                 for(int k=0;k<dp[i-1].size();k++){
                    string word2=dp[i-1][k];

                    if(check(word2,word1)){
                        dp1[i][j]=max(dp1[i][j],1+dp1[i-1][k]);
                        ans=max(ans,dp1[i][j]);
                    }
                 }
             }
        }
        for(int i=0;i<dp1.size();i++){
            for(int j=0;j<dp1[i].size();j++){
                cout<<dp1[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }

        return ans;
    }
};