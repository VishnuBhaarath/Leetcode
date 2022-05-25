class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       
        for(int i=0;i<nums.size();i++){
            int val=nums[abs(nums[i])-1];
            if(val<0){
                return abs(nums[i]);
            }  
            nums[abs(nums[i])-1]=nums[abs(nums[i])-1]*(-1);
        }
        
        return 0;
    }
};