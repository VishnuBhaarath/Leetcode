class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int val=v[n/2];
        int ans=0;
        for(int i=0;i<v.size();i++){
             int dif=abs(v[i]-val);
             if(dif%x!=0){
                return -1;
             }
             int q=dif/x;
             ans+=q;
        }
        return ans;
    }
};