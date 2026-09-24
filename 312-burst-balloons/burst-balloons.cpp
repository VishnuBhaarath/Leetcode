class Solution {
public:
    vector<vector<int>> dp;
    int func(int i,int j,vector<int> & nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        for(int idx=i;idx<=j;idx++){
            int l=1;
            int r=1;
            if((i-1)>=0){
                l=nums[i-1];
            }
            if((j+1)<nums.size()){
                r=nums[j+1];
            }
            int val=l*r*nums[idx]+func(i,idx-1,nums)+func(idx+1,j,nums);
            ans=max(ans,val);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return func(0,n-1,nums);
    }
};