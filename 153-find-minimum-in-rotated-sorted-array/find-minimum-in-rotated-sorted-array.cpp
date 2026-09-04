class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;

        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>=nums[0] && nums[m]>=nums[n-1]){
                 l=m+1;
            }
            else if(nums[m]<=nums[0] && nums[m]<=nums[n-1]){
                r=m;
            }
            else if(nums[m]>=nums[0] && nums[m]<=nums[n-1]){
                r=m;
            }
        }
        return nums[r];
    }
};