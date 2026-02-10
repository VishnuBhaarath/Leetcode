class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         int cnt1=func(nums,k);
       
         int cnt2=func(nums,k-1);
     
         return cnt1-cnt2;
    }
    int func(vector<int>& nums,int k){
         unordered_map<int,int> umap;
         int n=nums.size();
         int l=0;
         int r=0;
         int res=0;
         while(r<nums.size()){
            umap[nums[r]]+=1;
            if(umap[nums[r]]==1){
                k-=1;
            }
            while(k<0){
                 umap[nums[l]]-=1;
                 if(umap[nums[l]]==0){
                    k+=1;
                 }
                 l+=1;
            }
            res+=(r-l+1);
            r+=1;
           
         }
         return res;
    }
};