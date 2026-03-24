class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void func(vector<int>&nums,int i,vector<int> &v){
        
         
         if(i==nums.size()){
              ans.push_back(v);
            return;
         }
        v.push_back(nums[i]);
         func(nums,i+1,v);
         v.pop_back();
         func(nums,i+1,v);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        func(nums,0,v);
        return ans;
    }
};