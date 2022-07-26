class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][0]==grid[0][j]){
                    int k=1;
                    int t=0;
                    while(k<grid.size()){
                        if(grid[i][k]!=grid[k][j]){
                            t=1;
                            break;
                        }
                        k+=1;
                    }
                    if(t==0){
                        cnt+=1;
                    }
                }
            }
        }
        return cnt;
    }
};