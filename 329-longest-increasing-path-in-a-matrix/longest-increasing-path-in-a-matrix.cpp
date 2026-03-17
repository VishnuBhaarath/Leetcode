class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> r={1,-1,0,0};
        vector<int> c={0,0,1,-1};
        int ans=1;
          vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 queue<pair<pair<int,int>,int>> q;

                 q.push({{i,j},1});
              //   dp[i][j]=1;
                 while(!q.empty()){
                
                     pair<int,int> p=q.front().first;
                     int d=q.front().second;
                     ans=max(ans,d);
                     q.pop();
                     int x=p.first;
                     int y=p.second;
                     dp[x][y]=max(dp[x][y],d);
                     for(int k=0;k<4;k++){
                        int x1=x+r[k];
                        int y1=y+c[k];
                        if(x1>=0 && x1<n){
                             if(y1>=0 && y1<m){
                                 if(matrix[x1][y1]>matrix[x][y] && dp[x1][y1]< d+1){
                                    q.push({{x1,y1},d+1});
                                    dp[x1][y1]=d+1;
                                 }
                             }
                        }
                     }
                 
                     }
                 }
        
        }
return ans;
    }
};