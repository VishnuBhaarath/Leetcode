class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            if(umap[nums[i]]!=0){
                int idx=umap[nums[i]];
                idx-=1;
                if(abs(i-idx)<=k){
                    return true;
                }
            }
            umap[nums[i]]=(i+1);
        }
        return false;
    }
};