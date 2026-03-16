class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=m+n){
            return false;
        }
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        dp[0][0]=1;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0){

                }
                else if(i==0){
                   if(s2[j-1]==s3[j-1]){
                       if(dp[i][j-1]==1){
                          dp[i][j]=1;
                       }
                   }
                }
                else if(j==0){
                    if(s1[i-1]==s3[i-1]){
                         if(dp[i-1][j]==1){
                            dp[i][j]=1;
                         }
                    }
                }
                else{
                    int idx=i-1+j-1+1;
                    
                    if(s1[i-1]==s3[idx]){
                      if(dp[i-1][j]==1){
                        dp[i][j]=1;
                      }
                    }
                    if(s2[j-1]==s3[idx]){
                      if(dp[i][j-1]==1){
                        dp[i][j]=1;
                      }
                    }
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
        return dp[n][m];
    }
};