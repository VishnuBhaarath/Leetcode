class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            map<int,int> umap;
              map<int,int> umap1;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<1 || matrix[i][j]>n){
                    return false;
                }
                 if(matrix[j][i]<1 || matrix[j][i]>n){
                    return false;
                }
                umap[matrix[i][j]]+=1;
                if(umap[matrix[i][j]]>1){
                    return false;
                }
                umap1[matrix[j][i]]+=1;
                if(umap1[matrix[j][i]]>1){
                    return false;
                }
            }
        }
        
         
        return true;
    }
};