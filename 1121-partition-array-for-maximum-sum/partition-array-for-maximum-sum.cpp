class Solution {
public:
   
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
       vector<int> dp(n+1,0); 


       for(int i=n-1;i>=0;i--){
        int ans=INT_MIN;
        int currMAX=arr[i];
        for(int j = i; j < std::min(i+k, (int)(arr.size())); j++){
            currMAX=max(currMAX,arr[j]);
            int sum=(j-i+1)*currMAX+dp[j+1];
         
            ans=max(ans,sum);
        }
       
        dp[i]=ans;
      }
     
       return dp[0];
      
    }
};