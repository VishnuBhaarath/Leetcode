class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        int val1=nums[1];
        int val2=nums[2];
        if(nums[2]<nums[1]){
           val1=nums[2];
           val2=nums[1];
        }
       
        for(int i=3;i<nums.size();i++){
             if(nums[i]<=val1){
                 val2=val1;
                 val1=nums[i];
             }
             else if(nums[i]<val2){
                 val2=nums[i];
             }
        }
        sum+=val1;
        sum+=val2;

        return sum;
       
    }
};