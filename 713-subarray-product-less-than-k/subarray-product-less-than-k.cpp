class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         int n=nums.size();
         int l=0;
         int r=0;
         if(k==0){
            return 0;
         }
         long long int sum=1;
         long long int ans=0;
         while(r<nums.size()){
            sum=sum*nums[r];
            while(sum>=k){
                sum=sum/nums[l];
                l+=1;
                if(l>r){
                    break;
                }
            }
            int res=(r-l+1);
            ans+=res;
            r+=1;
         }
         return ans;
    }
};