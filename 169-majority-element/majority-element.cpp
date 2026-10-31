class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ans=nums[i];
            }
            else{
                if(nums[i]==ans){
                    cnt+=1;
                }
                else{
                    cnt-=1;
                }
            }
        }
        return ans;
    }
};