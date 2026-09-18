class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> v;
        int ans=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
     
        int temp=0;
        for(int i=n-1;i>=0;i--){
           
            if(dp[i]==ans){
                if(temp % nums[i]==0){
                v.push_back(nums[i]);
                ans-=1;
                temp=nums[i];
                }
            }
        }
        return v;
    }
};