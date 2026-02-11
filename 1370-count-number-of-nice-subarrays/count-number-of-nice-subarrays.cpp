class Solution {
public:
 int fun(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int cnt=0;
        while(r<n){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
          
                cnt+=(r-l+1);
            
            r++;
        }
        return cnt;
        
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
       int cnt1=fun(nums,k);
       int cnt2=fun(nums,k-1);
       cout<<cnt1;
       cout<<" ";
       cout<<cnt2;
       cout<<"\n";
       return fun(nums,k)-fun(nums,k-1);
    }
};