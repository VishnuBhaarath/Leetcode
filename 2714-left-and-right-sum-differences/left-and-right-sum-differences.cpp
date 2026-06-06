class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<int> v;
        int ls=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            v.push_back(abs(sum-ls));
            ls+=nums[i];
        }
        return v;
    }
};