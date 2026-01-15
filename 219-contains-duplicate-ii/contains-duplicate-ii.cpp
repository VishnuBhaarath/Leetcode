class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            if(umap[nums[i]]==0){
                umap[nums[i]]=i+1;
            }
            else{
                int tp=umap[nums[i]];
                if((i+1-tp)<=k){
                    return true;
                }
                umap[nums[i]]=i+1;
            }
        }
        return false;
    }
};