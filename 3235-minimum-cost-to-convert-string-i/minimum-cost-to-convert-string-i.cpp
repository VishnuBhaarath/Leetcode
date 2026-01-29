class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char,char>,int> umap1;
      
        vector<vector<long long int>> dp(26,vector<long long int>(26,LONG_LONG_MAX));
        for(int i=0;i<original.size();i++){
             int idx1=original[i]-'a';
             int idx2=changed[i]-'a';
             dp[idx1][idx2]=min(dp[idx1][idx2],(long long int)(cost[i]));

        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                if(i==j){
                    dp[i][j]=0;
                }
            }
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dp[i][k]!=LONG_LONG_MAX && dp[k][j]!=LONG_LONG_MAX)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        long long c=0;
        for(int i=0;i<source.size();i++){
            if(dp[source[i]-'a'][target[i]-'a']==LONG_LONG_MAX){
                return -1;
            }
            c+=dp[source[i]-'a'][target[i]-'a'];
        }
        return c;
    }
};