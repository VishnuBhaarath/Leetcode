class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]=i;
        }
        for(int i=0;i<operations.size();i++){
            int idx=umap[operations[i][0]];
            nums[idx]=operations[i][1];
            umap[operations[i][1]]=idx;
        }
        return nums;
    }
};