class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int diff=abs(nums[0])-0;
        int val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i])<diff){
                diff=abs(nums[i]);
                val=nums[i];
            }
            else if(abs(nums[i])==diff){
                if(val<nums[i]){
                    val=nums[i];
                }
            }
        }
                     return val;
    }
};