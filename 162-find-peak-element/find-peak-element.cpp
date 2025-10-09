class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m==0){
                if(nums[m]>nums[m+1]){
                    return m;
                }
                else{
                    l=m+1;
                }
            }
            else if(m==(n-1)){
                if(nums[m]>nums[m-1]){
                    return m;
                }
                else{
                    r=m-1;
                }
            }
            else{
                if(nums[m]>nums[m+1] && nums[m]>nums[m-1]){
                    return m;
                }
                else if(nums[m]<=nums[m+1]){
                    l=m+1;
                }
                else{
                   r=m-1;
                }
            }
        }
        return -1;
    }
};