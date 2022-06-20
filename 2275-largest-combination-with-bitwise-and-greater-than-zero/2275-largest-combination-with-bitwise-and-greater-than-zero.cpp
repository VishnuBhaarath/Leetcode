class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int,int> umap;
        int ans=1;
        for(int i=0;i<candidates.size();i++){
            int n=candidates[i];
            int j=0;
            while(n){
                if((n&1)==1){
                    umap[j]+=1;
                    ans=max(ans,umap[j]);
                }
                j+=1;
                n=n>>1;
            }
            
        }
        return ans;
    }
};