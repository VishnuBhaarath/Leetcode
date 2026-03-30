class Solution {
public:
    vector<vector<int>> dp;

    int func(vector<int>&v,int i,int j){
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
            l=v[i-1];
         }
         if((j+1)<v.size()){
            r=v[j+1];
         }
         int val=v[idx]*l*r+func(v,i,idx-1)+func(v,idx+1,j);
         ans=max(ans,val);
       }
       return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
      
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return func(nums,0,n-1);
       // return ans;
    }
};