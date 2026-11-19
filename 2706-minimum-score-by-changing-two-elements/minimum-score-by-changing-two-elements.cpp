class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==3){
            return 0;
        }
        int val1=nums[n-1]-nums[2];
        int val2=nums[n-3]-nums[0];
        int val3=nums[n-2]-nums[1];
        return min(val3,min(val1,val2));
    }
};