class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int left=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                left=m;
                r=m-1;
            }
            else if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
        }

       int right=-1;
       l=0;
       r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                right=m;
                l=m+1;
            }
            else if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
        }
      return {left,right};

    }
};