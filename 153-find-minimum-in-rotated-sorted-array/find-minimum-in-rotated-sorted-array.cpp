class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
    if(nums[0]<nums[r]){
        return nums[0];
    }
    if(n==1){
        return nums[0];
    }
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(m-1>=0 && m+1<n){
                if(nums[m]<nums[m-1] && nums[m]<nums[m+1]){
                    return nums[m];
                }
                if(nums[m]>nums[m-1] && nums[m]<nums[m+1]){
                    if(nums[m]>nums[0]){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
                else if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                    return nums[m+1];
                }
            }
            else if(m-1>=0){
                if(nums[m]>nums[m-1]){
                    r=m-1;
                }
                else {
                    return nums[m];
                }
            }
            else if(m+1<n){
                if(nums[m+1]>nums[m]){
                    return nums[m];
                }
                else{
l=m+1;
                }
            }
        }
        return -1;
    }
};