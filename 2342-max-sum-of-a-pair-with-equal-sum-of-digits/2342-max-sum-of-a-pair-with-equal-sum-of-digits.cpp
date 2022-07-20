class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int> umap;
        map<int,int>umap1;
        int x=-1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int val=nums[i];
            while(val){
                sum+=(val%10);
                val=val/10;
            }
            if(umap1[sum]==0){
                umap[sum]=nums[i];
            }
            else{
                int ans=nums[i]+umap[sum];
                umap[sum]=max(umap[sum],nums[i]);
                x=max(x,ans);
            }
            umap1[sum]+=1;
        }
        return x;
    }
};