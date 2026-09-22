class Solution {
public:
    int cnt=0;
    int func(vector<int>& nums,int target,int sum,int i){
         if(i==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
         }
         return func(nums,target,sum+nums[i],i+1)+func(nums,target,sum-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return func(nums,target,0,0);
        //return cnt;
    }
};