class Solution {
public:
    vector<vector<int>> dp;
    set<vector<int>> s;
    void func(vector<int>&nums,int i,vector<int>&v){
        if(i==nums.size()){
            if(s.find(v)==s.end()){
                s.insert(v);
                dp.push_back(v);
              
            }
              return;
        }
        v.push_back(nums[i]);
        func(nums,i+1,v);
        v.pop_back();
         func(nums,i+1,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        func(nums,0,v);
        return dp;
    }
};