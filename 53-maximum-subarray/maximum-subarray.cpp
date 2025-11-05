class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum >= 0) {
                if ((sum + nums[i]) >= 0) {
                    sum += nums[i];
                    ans=max(ans,sum);
                } else {
                    sum=nums[i];
                    ans=max(ans,sum);

                }
            } else {
                if(nums[i]>=sum){
                    sum=nums[i];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};