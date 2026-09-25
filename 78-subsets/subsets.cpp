class Solution {
public:
    vector<vector<int>> ans;
    void func(int i,vector<int>&nums,vector<int>v){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        func(i+1,nums,v);
        v.pop_back();
        func(i+1,nums,v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        
        func(0,nums,{});
        return ans;
    }
};