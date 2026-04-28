class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       
       long long int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
             long long int psum=0;
             for(int j=0;j<i;j++){
               psum+=abs(nums[i]-nums[j]);
             }
             for(int k=i+1;k<nums.size();k++){
psum+=abs(nums[i]-nums[k]);
             }
             ans=min(ans,psum);
        }
        return ans;
    }
};