class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums[0]-=k;
        int val=nums[0]+1;
        set <int> umap;
        umap.insert(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(val==nums[i]){
                val+=1;
            }
            else if(val<nums[i]){
               int diff= nums[i]-val;
               if(k<diff){
                nums[i]-=k;
                val=nums[i]+1;
               }
               else if (diff>0){
                nums[i]-=(diff);
                val=nums[i]+1;
               }
               else{
                val=nums[i]+1;
               }
            }
            else{
                int diff=val-nums[i];
                if(k>=diff){
                    nums[i]+=(diff);
                    val+=1;
                }
            }
            umap.insert(nums[i]);
        }
       
        return umap.size();
    }
};