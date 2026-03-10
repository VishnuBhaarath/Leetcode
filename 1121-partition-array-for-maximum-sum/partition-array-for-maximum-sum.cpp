class Solution {
public:
  
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
     
       vector<int> dp(n+1,0);
       dp[n-1]=arr[n-1];
       for(int i=n-2;i>=0;i--){
          int val=0;
          int ans=0;
         for(int j=i;j<min(n,i+k);j++){
             val=max(val,arr[j]);
             int sum=(j-i+1)*val;
             int temp=0;
             if(j+1<n){
                temp+=dp[j+1];
             }
             ans=max(ans,sum+temp);
             dp[i]=max(dp[i],ans);

         }
       }
      
        return dp[0];
    }
};