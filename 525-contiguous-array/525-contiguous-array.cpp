class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> presum;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
          nums[i]=sum;
        }
        
        map<int,int> umap;
        for(int i=n-1;i>=0;i--){
            umap[nums[i]]=i+1;
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                ans=max(ans,i+1);
            }
            else{
                int idx=umap[nums[i]];
                if(idx!=0){
                    ans=max(ans,i+1-idx);
                }
            }
        }
        return ans;
    }
};