class Solution {
public:
 int fun(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        int cnt=0;
        while(r<n){
             if(nums[r]%2!=0){
                 cnt+=1;
             }
             while(cnt>k){
                 if(nums[l]%2!=0){
                     l+=1;
                     cnt-=1;
                     //break;
                 }
                 else{
                    l+=1;
                 }
             }
            
             ans+=(r-l)+1;
             r+=1;
        }
        return ans;
        
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
       int cnt1=fun(nums,k);
     
       int cnt2=fun(nums,k-1);
     
      
       return cnt1-cnt2;
    }
};