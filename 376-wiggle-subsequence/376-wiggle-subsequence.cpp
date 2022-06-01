class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc=dec+1;
            }
            else if(nums[i-1]>nums[i]){
                dec=inc+1;
            }
            ans=max(ans,inc);
            ans=max(ans,dec);
        }
        return ans;
    }
};