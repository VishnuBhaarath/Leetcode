class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int cnt=0;
        int cnt1=0;
        int val=abs(matrix[0][0]);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                sum+=abs(matrix[i][j]);
                if(abs(matrix[i][j])<val){
                    val=abs(matrix[i][j]);
                }
                if(matrix[i][j]==0){
                    cnt+=1;
                }
                if(matrix[i][j]<0){
                    cnt1+=1;
                }
            }
        }
        if(cnt1%2 ==0){
            return sum;
        }
        else{
            if(cnt>0){
                return sum;
            }
            else{
               return sum-(2*val);
            }
        }
          return 0;
    }
};