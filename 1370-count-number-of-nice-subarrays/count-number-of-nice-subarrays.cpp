class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> umap;
        int cnt=0;
        umap[0]+=1;
        int ans=0;
        for(auto it:nums){
            if((it%2)!=0){
                cnt+=1;
            }
            ans+=umap[cnt-k];
            umap[cnt]+=1;

        }
        return ans;
    }
};