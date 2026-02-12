class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
         
            if(sum==0){
               int sz=i+1;
               ans=max(ans,sz);
            }
            else{
                 int val=umap[sum];
                 if(val!=0){
                    int sz=i+1-val;
                    ans=max(ans,sz);
                 }

            }
            if(umap[sum]==0){
                umap[sum]=i+1;
            }
         

        }
        return ans;
    }
};