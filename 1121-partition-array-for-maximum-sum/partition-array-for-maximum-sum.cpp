class Solution {
public:
  
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp;
        dp.resize(n+1,0);

   //   func(arr,0,k,n);
       

        for(int i=n-1;i>=0;i--){
            int val=-1;
            int ans=-1;
            for(int j=i;j<min(n,i+k);j++){
 val=max(val,arr[j]);
          int sz=(j-i+1);
          int val1=sz*val;
          int sum=val1+dp[j+1];
          ans=max(ans,sum);

            }
            dp[i]=ans;
        }
         
      return dp[0];
    }
};