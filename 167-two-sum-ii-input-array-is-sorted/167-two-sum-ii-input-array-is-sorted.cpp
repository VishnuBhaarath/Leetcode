class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            if(sum>target){
                j-=1;
            }
            else{
                i+=1;
            }
        }
        return v;
    }
};