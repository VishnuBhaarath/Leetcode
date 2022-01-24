class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        vector<int> ans;
        for(auto x:umap){
            if(x.second==1){
                if(umap[x.first-1]==0){
                    if(umap[x.first+1]==0){
                        ans.push_back(x.first);
                    }
                }
            }
        }
        return ans;
    }
};