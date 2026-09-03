class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        if(nums[l]<=nums[r]){
            return nums[l];
        }
        while(l<=r){
            int m=l+(r-l)/2;
            cout<<m;
            cout<<"\n";
            if(m+1<n && m-1>=0){
            if(nums[m]>nums[m+1] && nums[m]>nums[m-1]){
                return nums[m+1];
               l=m+1;
            }
            else if(nums[m]>nums[m-1] && nums[m]<nums[m+1]){
                if(nums[0]>nums[m]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else if(nums[m]<nums[m-1]){
                return nums[m];
            }
            }
            else if(m+1<n){
                if(nums[m]>nums[n-1]){
                    l=m+1;
                }
                else{
                    return nums[m];
                }
            }
            else if(m-1 >=0){
                if(nums[m] > nums[0]){
                    r=m-1;
                }
                else{
                    return nums[m];
                }
            }
        }
        return -1;
    }
};