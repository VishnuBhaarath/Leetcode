class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> umap;
        int ans=0;
        int val=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==key){
                umap[nums[i]]+=1;
            }
            if(umap[nums[i]]>ans){
                ans=umap[nums[i]];
                val=nums[i];
            }
        }
        
        return val;
    }
};