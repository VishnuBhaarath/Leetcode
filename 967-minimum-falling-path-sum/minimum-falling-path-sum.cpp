class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=matrix[0][0];
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i>0){
                 int val=matrix[i-1][j];
                 if(j+1<matrix[0].size()){
                    val=min(val,matrix[i-1][j+1]);
                 }
                 if(j-1>=0){
                    val=min(val,matrix[i-1][j-1]);
                 }
                 matrix[i][j]=matrix[i][j]+val;
                 }
                 if(i==n-1){
                    if(j==0){
                        ans=matrix[i][j];
                    }
                    else{
                        ans=min(ans,matrix[i][j]);
                    }
                 }
               
                 
            }
           
        }

          return ans;
        
       
    }
};