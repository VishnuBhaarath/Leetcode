class Solution {
public:
    int cnt=0;
    void func(vector<int>& nums, long long int target, long long int sum,int i){
        if(i==nums.size()){
            if(target==sum){
                cnt+=1;
            }
            return;
        }
        func(nums,target,sum+nums[i],i+1);
        func(nums,target,sum-nums[i],i+1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        func(nums,target,0,0);
        return cnt;
    }
};