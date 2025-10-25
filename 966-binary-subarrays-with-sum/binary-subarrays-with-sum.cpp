class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> umap;
        umap[0]+=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cnt+=(umap[sum-goal]);
            umap[sum]+=1;
        }
        return cnt;
    }
};