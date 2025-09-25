class Solution {
public:
    int cnt=0;
    int func(vector<int>& nums, long long int target, long long int sum,int i){
        if(i==nums.size()){
            if(target==sum){
                return 1;
            }else{
                return 0;
            }
        }
        return func(nums,target,sum+nums[i],i+1)+func(nums,target,sum-nums[i],i+1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums,target,0,0);
        
    }
};