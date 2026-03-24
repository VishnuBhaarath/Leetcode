class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    void func(vector<int>& nums,vector<int> v,int i){
         if(i==nums.size()){
            if(s.find(v)==s.end()){
                s.insert(v);
                ans.push_back(v);
            }
            return;
         }

         v.push_back(nums[i]);
         func(nums,v,i+1);
         v.pop_back();
         func(nums,v,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        func(nums,v,0);
        return ans;
    }
};