class Solution {
public:
    vector<int> r={1,-1,0,0};
    vector<int> c={0,0,1,-1};
    vector<vector<int>> dp;
    int traversal(int i,int j,vector<vector<int>>& matrix,int d){
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<4;k++){
            int x1=i+r[k];
            int y1=j+c[k];
            if((x1>=0 && x1<n) && (y1>=0 && y1<m)){
                 
                 if(matrix[x1][y1]>matrix[i][j]){
                    dp[i][j]=max(dp[i][j],1+traversal(x1,y1,matrix,d+1));
                 }
            }

        }
     
        if(dp[i][j]==-1){
            dp[i][j]=1;
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                traversal(i,j,matrix,0);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j];
                ans=max(ans,dp[i][j]);
                cout<<" ";
            }
            cout<<"\n";
        }
        return ans;
    }
};