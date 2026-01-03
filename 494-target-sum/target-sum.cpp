class Solution {
public:
    int func(vector<int>& nums, int i, int target, int sum) {
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            }
            else{
                return 0;
            }
        }
        return func(nums,i+1,target,sum+nums[i]) + func(nums,i+1,target,sum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        return func(nums,0,target,0);
    }
};