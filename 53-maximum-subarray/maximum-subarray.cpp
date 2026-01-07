class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
         int t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                t=1;
                break;
            }
            ans=max(ans,nums[i]);
        }
        if(t==0){
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=0){
                sum=0;
            }
            else{
                sum+=nums[i];
            }
            ans=max(ans,sum);
        }
       
        return ans;
    }
};