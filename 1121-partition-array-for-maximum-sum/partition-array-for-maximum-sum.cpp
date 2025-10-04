class Solution {
public:
    
    int func(vector<int>& arr,int i,int k,vector<vector<int>>&dp,int sz,vector<int> &dp1){
        if(i==arr.size()){
            return 0;
        }
        if(dp1[i]!=-1){
            return dp1[i];
        }
       
        unsigned long long int val=0;
        for (int j = i; j < std::min(static_cast<int>(arr.size()), i + k); j++){
          
           unsigned long long int sum=(dp[i][j-i+1])*(j-i+1)+func(arr,j+1,k,dp,(j-i+1),dp1);
           val=max(val,sum);
           
        }
       
        return dp1[i]=val;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,0));
        vector<int> dp1 (n+1,-1);

        for(int i=1;i<=k;i++){
    
            dp[n-1][i]=arr[n-1];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=k;j>=1;j--){
               
                int val=dp[i+1][j-1];
                val=max(val,arr[i]);
                dp[i][j]=val;
            }
        }
      

       

       
        return func(arr,0,k,dp,0,dp1);
        
       
    }
};