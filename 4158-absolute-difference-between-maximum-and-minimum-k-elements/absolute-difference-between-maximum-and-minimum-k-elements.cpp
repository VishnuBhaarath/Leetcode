class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        int val=0;
        while(i<k){
             val+=(nums[j]-nums[i]);
             i+=1;
             j-=1;
        }
        return val;
    }
};