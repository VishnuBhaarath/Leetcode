class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
            }
        }

        for(int j=1;j<matrix[0].size();j++){
             if(matrix[0][j]=='1'){
                dp[0][j]+=(dp[0][j-1]+1);
             }
        }

        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+dp[i][j-1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                if(dp[i][j]!=0){
                   
                    int w=dp[i][j];
                    int h=1;
                    int area=1*w;
                    ans=max(ans,area);
                    int k=i-1;
                    while(k>=0){
                        if(dp[k][j]>0){
                            w=min(w,dp[k][j]);
                            h=i-k+1;
                            area=h*w;
                            ans=max(ans,area);
                        }
                        else{
                            break;
                        }
                        k-=1;
                    }
                }
            }
        }
        
        return ans;
    }
};