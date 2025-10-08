class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int st=nums[n-1];
        int ans=5000;
        while(l<=r){
            int mid=l+(r-l)/2;
          
            ans=min(ans,nums[mid]);
         
            if(nums[mid]>st){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return ans;
    }
};