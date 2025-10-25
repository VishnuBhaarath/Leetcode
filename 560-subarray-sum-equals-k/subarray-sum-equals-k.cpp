class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> umap;
        umap[0]+=1;
        int sum=0;
        int cnt=0;
        for(auto it: nums){
            sum+=it;
            cnt+=umap[sum-k];
            umap[sum]+=1;
        }
        return cnt;
    }
};