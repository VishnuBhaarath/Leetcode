class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       
       long long int ans=INT_MAX;
       int n=nums.size();
       int val=nums[n/2];
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=abs(nums[i]-val);
       }
       return sum;
    }
};