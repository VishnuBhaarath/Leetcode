class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
           if(nums[i]>=0){
              if(sum<0){
                sum=nums[i];
              }
              else{
              sum+=nums[i];
              }
           }
           else{
              
                 if(sum+nums[i]>=0){
                    sum+=nums[i];
                 }
                 else{
                    sum=nums[i];
                 }
              
           }
        
           ans=max(ans,sum);
        }
        return ans;
    }
};