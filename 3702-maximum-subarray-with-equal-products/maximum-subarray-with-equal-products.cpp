class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++){
            unsigned long long  num=nums[i];
            int gcd1=nums[i];
            int lcm1=nums[i];
            for(int j=i+1;j<nums.size();j++){
                gcd1=gcd(gcd1,nums[j]);
                lcm1=lcm(lcm1,nums[j]);
                num*=(unsigned long long)(nums[j]);
                if(gcd1*lcm1==num){
                    int sz=(j-i+1);
                    ans=max(ans,sz);
                }
            }
        }
        return ans;
    }
};