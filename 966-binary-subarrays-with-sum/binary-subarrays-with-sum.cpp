class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> umap;
        umap[0]+=1;
        int sum=0;
        int cnt=0;
        for(auto it:nums){
            sum+=it;
            cnt+=umap[sum-goal];
            umap[sum]+=1;
        }
        return cnt;
    }
};