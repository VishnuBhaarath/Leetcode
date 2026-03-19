class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
             if(nums[i]>=0){
                if(sum<0){
                     ans=max(ans,sum);
                     sum=0;
                }
                sum+=nums[i];
                ans=max(ans,sum);
             }
             else{
                 if((abs(nums[i]<=abs(sum)))){
                    if(sum<0){
                        sum=max(sum,nums[i]);
                    }
                    else{
                    sum+=nums[i];
                    }
                    ans=max(ans,sum);
                 }
                 else{
                    sum=0;
                 }
             }
               
        }
        return ans;
    }
};