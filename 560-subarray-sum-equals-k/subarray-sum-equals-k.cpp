class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int sum=0;
        map<int,int> umap;
        umap[0]+=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
                int val=umap[sum-k];
                cnt+=val;
            

            umap[sum]+=1;
        }
        return cnt;
    }
};