class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> umap;
        int l=0;
        int r=0;
        long long int sum=0;
        long long int ans=0;
        for(int i=0;i<nums.size();i++){
             umap[nums[i]]+=1;
             sum+=(long long int)(nums[i]);
             while(umap[nums[i]]>1){
                 umap[nums[l]]-=1;
                 sum-=nums[l];
                 l+=1;
             }
             int sz=(i-l+1);
             if(sz>k){
                umap[nums[l]]-=1;
                sum-=(long long int)(nums[l]);
                l+=1;
             }
             sz=(i-l+1);
             if(sz==k){
                ans=max(ans,sum);
             }
        }
        return ans;
    }
};