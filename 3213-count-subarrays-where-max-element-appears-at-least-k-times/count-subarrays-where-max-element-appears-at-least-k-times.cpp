class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>num){
                num=nums[i];
            }
        }
        int l=0;
       long long int cnt=0;
       long long int n=nums.size();
       long long int ans=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==num){
                cnt+=1;
             }
             while(cnt==k){
                long long int res=(n-i);
                 ans+=res;
                 if(nums[l]==num){
                    cnt-=1;
                 }
                 l+=1;
             }
        }
        return ans;
    }
};