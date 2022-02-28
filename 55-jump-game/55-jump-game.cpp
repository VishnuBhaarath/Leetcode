class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx=nums[0];
        if(idx>=nums.size()-1){
            return true;
        }
        for(int i=1;i<nums.size();i++){
            if(i>idx){
                return false;
            }
            int val=i+nums[i];
            if(val>idx){
                idx=val;
            }
            if(idx>=nums.size()-1){
                return true;
            }
        }
        return true;
    }
};