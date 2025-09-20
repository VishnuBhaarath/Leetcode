class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                 int val=matrix[i-1][j];
                 if(j+1<matrix[0].size()){
                    val=min(val,matrix[i-1][j+1]);
                 }
                 if(j-1>=0){
                    val=min(val,matrix[i-1][j-1]);
                 }
                 matrix[i][j]=matrix[i][j]+val;
                 cout<<matrix[i][j];
                 cout<<" ";
                 
            }
            cout<<"\n";
        }

        int ans=matrix[n-1][0];
        for(int j=1;j<m;j++){
            ans=min(ans,matrix[n-1][j]);
        }
             return ans;
        
       
    }
};