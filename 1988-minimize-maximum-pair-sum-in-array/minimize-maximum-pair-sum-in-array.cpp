class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=nums[n-1]+nums[0]; 
        int i=0;
        int j=n-1;
        while(i<j){
            sum=max(sum,nums[i]+nums[j]);
            i+=1;
            j-=1;
        }
        return sum;
    }
};