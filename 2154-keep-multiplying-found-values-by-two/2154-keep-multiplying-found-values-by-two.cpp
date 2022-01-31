class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        while(1){
            if(umap[original]!=0){
                original=2*original;
            }
            else{
                return original;
            }
            
        }
        return original;
    }
};