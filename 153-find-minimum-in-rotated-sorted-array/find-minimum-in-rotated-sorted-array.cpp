class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int st=nums[0];
        if(nums[0]<nums[r]){
            return nums[0];
        }
        if(n==1){
            return nums[0];
        }
        int ans=5000;
        while(l<=r){
            int mid=l+(r-l)/2;
          
            ans=min(ans,nums[mid]);
         
            if(nums[mid]<st){
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};