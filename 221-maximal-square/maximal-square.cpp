class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]=='1'){
                dp[0][j]=1;
                ans=1;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    int val=dp[i-1][j-1];
                    val=min(val,dp[i][j-1]);
                    val=min(val,dp[i-1][j]);
                    ans=max(ans,val+1);
                    dp[i][j]=val+1;
                    
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
        return ans*ans;
    }
};