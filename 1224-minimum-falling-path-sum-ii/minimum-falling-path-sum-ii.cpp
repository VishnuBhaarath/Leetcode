class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        cout<<n;
        cout<<"\n";
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i>0){
                int val=INT_MAX;
                for(int k=0;k<grid.size();k++){
                     if(k!=j){
                        val=min(val,grid[i-1][k]);
                     }
                }
                grid[i][j]+=val;
                }
                if(i==n-1){
                if(j==0){
                   ans=grid[i][j];
                }
                else{
                    ans=min(ans,grid[i][j]);
                }
            }
            }
            
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                cout<<grid[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        return ans;
    }
};