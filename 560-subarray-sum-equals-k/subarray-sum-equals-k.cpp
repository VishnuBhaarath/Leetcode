class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int psum=0;
        umap[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            cnt+=umap[psum-k];
            umap[psum]+=1;
        }
        return cnt;
    }
};