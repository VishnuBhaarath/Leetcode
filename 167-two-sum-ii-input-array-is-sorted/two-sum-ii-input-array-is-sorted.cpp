class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        vector<int> v;
        while(i<j){
          
            if(nums[i]+nums[j]== target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(nums[i]+nums[j]>target){
                j-=1;
            }
            else if(nums[i]+nums[j]<target){
                i+=1;
            }
        }
        return v;
    }
};