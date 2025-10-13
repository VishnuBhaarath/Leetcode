class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> umap;
        unordered_map<int,int> umap1;
        for(int i=0;i<trust.size();i++){
            umap[trust[i][1]]+=1;
            umap1[trust[i][0]]+=1;
        }
        for(int i=1;i<=n;i++){
            if(umap[i]==(n-1) && umap1[i]==0){
                return i;
            }
        }
        return -1;
    }
};