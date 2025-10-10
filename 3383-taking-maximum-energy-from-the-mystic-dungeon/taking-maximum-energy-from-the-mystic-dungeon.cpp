class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=energy[n-1];
        int sum=energy[n-1];
        vector<int> dp (n,0);
        
        dp[n-1]=energy[n-1];
        for(int i=n-2;i>=0;i--){
            if((i+k)<n){
                dp[i]=energy[i]+dp[i+k];
                ans=max(ans,dp[i]);
            }
            else{
                dp[i]=energy[i];
                ans=max(ans,dp[i]);

            }
        }
        return ans;
    }
};