class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==1){
            int idx=nums[i];
            int j=i+1;
            if(j==n){
                break;
            }
            while(idx>0){
                dp[j]=1;
                if(j==(n-1)){
                    return true;
                }
                j+=1;
                if(j==n){
                    break;
                }
                idx-=1;
            }
            }
        }
        if(dp[n-1]==1){
            return true;
        }
        return false;
    }
};