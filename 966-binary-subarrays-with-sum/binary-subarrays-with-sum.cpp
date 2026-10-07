class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> umap;
        int sum=0;
        umap[0]+=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int val=umap[sum-goal];
            cnt+=val;
            umap[sum]+=1;
        }
        return cnt;
    }
};