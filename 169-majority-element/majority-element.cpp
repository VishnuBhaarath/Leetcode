class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt=1;
       int ans=nums[0];
       for(int i=1;i<nums.size();i++){
        if(nums[i]==ans){
            cnt+=1;
        }
        else{
            cnt-=1;
            if(cnt<0){
                cnt=1;
                ans=nums[i];
            }
        }
       }
       return ans;
    }
};