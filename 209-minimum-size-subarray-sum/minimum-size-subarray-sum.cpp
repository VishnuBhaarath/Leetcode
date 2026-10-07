class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int ans=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                int sz=r-l+1;
                if(ans==0){
                    ans=sz;
                }
                else{
                    ans=min(ans,sz);
                }
                sum-=nums[l];
                l+=1;
            }
            r+=1;
        }
        return ans;
    }
};