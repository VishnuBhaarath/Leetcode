class Solution {
public:
    bool divideArray(vector<int>& nums) {
       map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        for(auto x:umap){
            if((x.second%2)!=0){
                return false;
            }
        }
        return true;
    }
};