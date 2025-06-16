class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]=i+1;
        }
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(umap[target-nums[i]]>0){
                if(i!=((umap[target-nums[i]])-1)){
                v.push_back(i);
                v.push_back((umap[target-nums[i]])-1);
                return v;}
            }
        }
        return v;
    }
};