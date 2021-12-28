class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v={1,2,3,4};
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            cout<<" ";
        }
        int currsum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(currsum+nums[i]<nums[i]){
                currsum=nums[i];
            }
            else{
                currsum+=nums[i];
            }
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};