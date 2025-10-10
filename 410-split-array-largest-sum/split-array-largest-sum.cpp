class Solution {
public:
    int check(vector<int> & nums, int mid,int k){
         int cnt=1;
         int sum=0;
         for(int i=0;i<nums.size();i++){
             if(nums[i]>mid){
                return 0;
             }
             if(nums[i]+sum <= mid){
                sum+=nums[i];
             }
             else{
                cnt+=1;
                if(cnt>k){
                    return 0;
                }
                sum=nums[i];
             }
         }
         return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            r+=nums[i];
        }
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=check(nums,mid,k);
           
            if(val==1){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};