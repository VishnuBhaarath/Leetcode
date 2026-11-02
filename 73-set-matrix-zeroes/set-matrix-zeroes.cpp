class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r;
        vector<int> c;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                 if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                 }
            }
        }

        for(int i=0;i<r.size();i++){
            for(int j=0;j<m;j++){
                matrix[r[i]][j]=0;
            }
        }
        for(int j=0;j<c.size();j++){
            for(int i=0;i<n;i++){
                 matrix[i][c[j]]=0;
            }
        }
    }
};