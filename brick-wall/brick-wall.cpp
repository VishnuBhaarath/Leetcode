class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=0;
        for(int j=0;j<wall[0].size();j++){
            n+=wall[0][j];
        }
       
        map<int,int> umap;
        int ans=0;
        for(int i=0;i<wall.size();i++){
            int sum=0;
            for(int j=0;j<wall[i].size();j++){
                sum+=wall[i][j];
                umap[sum]+=1;
                if(n!=sum && sum!=0){
                    ans=max(ans,umap[sum]);
                }
                
            }
        }
    
        return wall.size()-ans;
    }
};