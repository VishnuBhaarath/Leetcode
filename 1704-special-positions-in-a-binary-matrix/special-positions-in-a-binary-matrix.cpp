class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        set<int> s;
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                 if(mat[i][j]==1){
                      int k=0;
                      int t=0;
                      while(k<mat.size()){
                         if(k!=i){
                            if(mat[k][j]==1){
                                t=1;
                                break;
                            }
                         }
                         k+=1;
                      }
                      if(t==0){
                        k=0;
                        while(k<mat[0].size()){
                         if(k!=j){
                            if(mat[i][k]==1){
                                t=1;
                                break;
                            }
                         }
                         k+=1;
                      }
if(t==0)
                        cnt+=1;
                      }
                        break;
                  }
                   
                 }
            }
        
        return cnt;
    }
};