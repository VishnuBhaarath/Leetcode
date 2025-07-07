class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> umap;
        umap[0]+=1;
        vector<int> v;
        v.push_back(0);
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int n=v.size();
            int sum=v[n-1]+nums[i];
            v.push_back(sum);
            cnt+=umap[sum-k];
               umap[sum]+=1;

        }
        return cnt;
    }
};