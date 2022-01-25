class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long int n=questions.size();
        vector<long long int> dp(n,0);
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
            long long int p=questions[i][0];
            long long int b=questions[i][1];
            long long int val=p;
            if((i+b+1)<n){
                val+=dp[i+b+1];
            }
            if(i+1<n){
                val=max(val,dp[i+1]);
            }
            dp[i]=val;
            ans=max(ans,val);
            
        }
      
        return ans;
    }
};