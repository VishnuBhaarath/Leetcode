class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int r=nums[0];
        if(r>=n-1){
            return true;
        }
        while(i<=r){
            r=max(r,i+nums[i]);
            if(r>=n-1){
                return true;
            }
            i+=1;
        }
        return false;
    }
};