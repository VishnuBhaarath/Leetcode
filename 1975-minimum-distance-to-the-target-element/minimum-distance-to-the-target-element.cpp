class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==target){
                int val=abs(i-start);
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                }
             }
        }
        return ans;
    }
};