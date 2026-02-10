class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        int sz=0;
        while(r<nums.size()){
             
             if(nums[r]==0){
                 if(k>0){
                    k-=1;
                     sz=r-l+1;
                    ans=max(ans,sz);
                    r+=1;
                 }
                 else{
                     while(nums[l]==1){
                         l+=1;
                     }
                     l+=1;
                     k=0;
                     sz=r-l+1;
                     ans=max(ans,sz);
                     r+=1;
                 }
             }
             else{
                sz=r-l+1;
                     ans=max(ans,sz);
                r+=1;
             }
        }
        return ans;
    }
};