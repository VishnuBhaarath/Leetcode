class Solution {
public:
    int func1(int i,int j, vector<int>& arr){
           int sz=(j-i)+1;
           int temp=arr[i];
           for(int k=i;k<=j;k++){
               temp=max(temp,arr[k]);
           }
           return temp*sz;
    }
    int func(int n,int k, vector<int> & arr,int i,vector<int>& dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        for(int j=i;j<min(n,i+k);j++){
            int sum=func1(i,j,arr)+func(n,k,arr,j+1,dp);
            ans=max(ans,sum);
          
            dp[i]=ans;
        }
     return ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int ans= func(n,k,arr,0,dp);
       
        return ans;
    }
};