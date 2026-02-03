class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int l1=0;
        int l2=0;
        int l3=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return false;
            }
            else if(nums[i]>nums[i-1]){
                l1=1;
                if(l2==1){
                    l3=1;
                }
            }
            else{
                if(l3==1){
                    return false;
                }
                if(l1==0){
                    return false;
                }
                l2=1;
            }
        }
        if(l1==1 && l2==1 && l3==1){
            return true;
        }
        return false;
    }
};