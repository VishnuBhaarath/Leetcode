class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> umap;
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
             umap[nums[i]]+=1;
             while(umap[nums[i]]>k){
                 umap[nums[l]]-=1;
                 l+=1;
             }
             int res=(i-l)+1;
             ans=max(ans,res);
        }
        return ans;
    }
};