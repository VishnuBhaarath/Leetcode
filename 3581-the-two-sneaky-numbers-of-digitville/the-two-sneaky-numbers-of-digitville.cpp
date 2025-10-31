class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> v(101,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            v[nums[i]]+=1;
            if(v[nums[i]]==2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};