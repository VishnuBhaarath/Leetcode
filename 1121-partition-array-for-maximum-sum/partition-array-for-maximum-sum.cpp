class Solution {
public:
    int func1(int i,int j,vector<int>&arr){
        int val=arr[i];
        for(int k=i;k<=j;k++){
            val=max(val,arr[k]);
        }
       
        return (j-i+1)*val;
    }
    int func(vector<int>&arr,int i,int k,int n,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        int val=0;
        for(int j=i;j<min(i+k,n);j++){
            val=max(val,arr[j]);
            int sum=(j-i+1)*val+func(arr,j+1,k,n,dp);
            ans=max(ans,sum);
           
            
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            int val=0;
            int ans=0;
            for(int j=i;j<min(i+k,n);j++){
               val=max(val,arr[j]);
               int sum=(j-i+1)*val;
               if((j+1)<n){
               sum+=dp[j+1];}
                ans=max(ans,sum);
            }
            dp[i]=ans;
        }
        //return func(arr,0,k,n,dp);
        return dp[0];

    }
};